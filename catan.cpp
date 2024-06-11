// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include "catan.hpp"

#define FALSE 0
#define TRUE 1

namespace ariel {

    Catan::Catan(Player& pl1, Player& pl2, Player& pl3){
        this->players = {pl1,pl2,pl3};
        board = Board();
    }
    Catan::~Catan(){}
    
    vector<Player>& Catan::ChooseStartingPlayer(){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(players.begin(), players.end(), std::default_random_engine(seed));
        this->turn = 0;
        cout << "The starting player is " << players[turn].getName() << "\n" << endl;
        return this->players;
    }
    
    void Catan::nextTurn(){
        this->turn = (this->turn + 1) % 3;
        cout << "It's your turn now " << players[turn].getName() << "\n" << endl;
    }
    
    int Catan::rollDice(){
        srand(time(0));
        int result = (rand() % 6 + 1) + (rand() % 6 + 1);
        for(unsigned int i=1; i<55; i++){
            string typeWithNum = board.getSpot(i).diceInSpot(result);
            if(typeWithNum!="0"){
                for(unsigned int p=0; p<players.size(); p++){
                    if(board.getSpot(i).getOwner() == players[p].getColor()){
                        if(typeWithNum == "Wood"){ players[p].addWood(1); }
                        if(typeWithNum == "Rock"){ players[p].addRock(1); }
                        if(typeWithNum == "Wool"){ players[p].addWool(1); }
                        if(typeWithNum == "Iron"){ players[p].addIron(1); }
                        if(typeWithNum == "Oats"){ players[p].addOats(1); }
                    }
                }
            }
        }
        return result;
    }

    bool Catan::placeSettlement(Player& p){
        if(players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn].getName() << endl;
            return false;
        }
        if(p.getWood() < 1 || p.getRock() < 1 || p.getOats() < 1 || p.getWool() < 1){
            cout<< "not enough resources" << endl;
            return false;
        }
        unsigned int spot;
        while(true){
            bool okToPlace = true;
            cin >> spot;
            if(spot == 0){ return false; }
            if(spot > 0 && spot < 55){
                if(board.getSpot(spot).getOwner() == ""){
                    vector<unsigned int> neighbors = board.getSpot(spot).getNeighbors();
                    for(unsigned int i=0; i<neighbors.size(); i++){
                        if(board.getSpot(neighbors[i]).getOwner() != ""){
                            cout << "Can't place a settelment neighbor to another" << endl;
                            okToPlace = false;
                            break; // breaks from for loop only
                        }
                    }
                    if(okToPlace) { break; }
                } else{ cout << "There's already a settlement" << endl;}
            } else { cout << "You are out of bounds (1-54)" << endl; }
        }
        p.builtSettlement();
        board.setOwner(spot, p.getColor());
        p.addPoint();
        return true;
    }
    
    bool Catan::upgradeSettlement(Player& p){
        if(players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn].getName() << endl;
            return false;
        }
        if(p.getIron() < 3 || p.getOats() < 2){
            cout<< "not enough resources" << endl;
            return false;
        }
        unsigned int spot;
        while(true){
            bool okToPlace = true;
            cin >> spot;
            if(spot == 0){ return false; }
            if(spot > 0 && spot < 55){
                if(board.getSpot(spot).getOwner() == p.getColor()){
                    break;
                } else{ cout << "Not yours to upgrade" << endl;}
            } else { cout << "You are out of bounds (1-54)" << endl; }
        }
        p.upgradedCity();
        board.setOwner(spot, p.getColor().replace(2, 2, "1;"));
        p.addPoint();
        return true;

    }

    bool Catan::trade(Player& p){
        if(players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn].getName() << endl;
            return false;
        }
        string name;
        while(true){
            cin >> name;
            if(name == "0"){ break; }
            for(unsigned int i=0; i<players.size(); i++){
                if(players[i].getName() == name && players[i] != p){}{
                    if(p.trade(players[i])){ 
                        cout << "Successfully traded." << endl;
                        return true;
                    }
                    cout << "Couldn't/wouldn't trade." << endl;
                    return false; 
                }
            }
            cout << "No player with such name." << endl;
        }
        return false; 
    }

    bool Catan::placeRoad(Player& p){
        if(players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn].getName() << endl;
            return false;
        }
        if(p.getWood() < 1 || p.getRock() < 1){
            cout<< "not enough resources" << endl;
            return false;
        }
        unsigned int from, to;
        while(true){
            cin >> from;
            cin >> to;
            if(from == 0 || to == 0){ return false; }
            if(from > 0 && from < 55 && to > 0 && to < 55){
                if(p.getColor() == board.getSpot(from).getOwner() || p.getColor() == board.getSpot(to).getOwner()
                || (board.getSpot(from).getOwner()!="" && p.getColor() == board.getSpot(from).getOwner().replace(2, 2, "0;"))
                || (board.getSpot(to).getOwner()!="" && p.getColor() == board.getSpot(to).getOwner().replace(2, 2, "0;"))){
                    if(board.getSpot(from).closeTo(board.getSpot(to))){
                        p.builtRoad();
                        vector<unsigned int> neighbors = this->board.getSpot(from).getNeighbors();
                        for(unsigned int i=0; i<neighbors.size(); i++){
                            if(board.getSpot(neighbors[i]) == board.getSpot(to)){
                                board.getSpot(from).setRoadOwner(p.getColor(), i);
                            }
                        }
                        neighbors = this->board.getSpot(to).getNeighbors();
                        for(unsigned int i=0; i<neighbors.size(); i++){
                            if(board.getSpot(neighbors[i]) == board.getSpot(from)){
                                board.getSpot(to).setRoadOwner(p.getColor(), i);
                            }
                        }
                        break;
                    } else{ cout << "There's no road between " << from << " and " << to << endl; }
                } else{ cout << "Cant place a road not connected to a settlement" << endl; }
            } else{ cout << "You are out of bounds (1-54)" << endl; }
        }
        return true;
    }
    
    void Catan::printBoard(){
        this->board.printBoard();
    }

    bool Catan::gotWinner(){
        for(unsigned int i=0; i < players.size(); i++){
            if(players[i].getPoints() >= 10){
                cout << "====================\n" << players[i].getName() << "Won!!!" <<"====================\n" << endl;
                return true;
            }
        }
        return false;
    }
}