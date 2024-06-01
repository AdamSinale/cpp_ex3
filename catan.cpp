// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include "catan.hpp"

#define FALSE 0
#define TRUE 1

namespace ariel {

    Catan::Catan(Player pl1, Player pl2, Player pl3){
        this->players = {pl1,pl2,pl3};
        board = Board();
        this->board.printBoard();
    }
    Catan::~Catan(){}
    
    vector<Player> Catan::ChooseStartingPlayer(){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(players.begin(), players.end(), std::default_random_engine(seed));
        this->turn = 0;
        cout << "The starting player is " << players[turn].getName() << "\n" << endl;
        return players;
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
                for(unsigned int p; p<players.size(); p++){
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

    bool Catan::placeSettelemnt(Player p){
        if(players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn].getName() << endl;
            return false;
        }
        unsigned int spot;
        while(true){
            bool okToPlace = true;
            cin >> spot;
            if(spot > 0 && spot < 55){
                if(board.getSpot(spot).getOwner() == ""){
                    vector<unsigned int> neighbors = board.getSpot(spot).getNeighbors();
                    for(unsigned int i=0; i<neighbors.size(); i++){
                        if(board.getSpot(neighbors[i]).getOwner() != ""){
                            cout << "Can't place a settelment neighbor to another" << endl;
                            okToPlace = false;
                            break;
                        }
                    }
                    if(okToPlace) { break; }
                } else{ cout << "There's already a settlement" << endl;}
            } else { cout << "You are out of bounds (1-54)" << endl; }
        }
        board.setOwner(spot-1, p.getColor());
        this->board.printBoard();
        return true;
    }
    
    bool Catan::placeRoad(Player p){
        if(players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn].getName() << endl;
            return false;
        }
        unsigned int from, to;
        while(true){
            cin >> from;
            cin >> to;
            if(from > 0 && from < 55 && to > 0 && to < 55){
                if(p.getColor() == board.getSpot(from).getOwner() || p.getColor() == board.getSpot(to).getOwner()){
                    if(board.getSpot(from).closeTo(board.getSpot(to))){
                        if(p.getWood()> 0 && p.getRock() > 0){
                            p.builtRoad();
                            this->board.printBoard();
                            // board.getSpot(from); add to spot
                            break;
                        } else{ cout<< "not enough resources" << endl; }
                    } else{ cout << "There's no road between " << from << " and " << to << endl; }
                } else{ cout << "Cant place a road not connected to a settlement" << endl; }
            } else{ cout << "You are out of bounds (1-54)" << endl; }
        }
        return true;
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