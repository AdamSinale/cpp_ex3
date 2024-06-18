// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include "catan.hpp"

#define FALSE 0
#define TRUE 1
using std::make_unique;

namespace ariel {

    Catan::Catan(Player& pl1, Player& pl2, Player& pl3){
        this->players = {pl1,pl2,pl3};
        board = Board();

        vector<unique_ptr<Devcard>> cards;
        cards.push_back(make_unique<Monopoly>());
        cards.push_back(make_unique<Monopoly>());
        cards.push_back(make_unique<YearOfPlenty>());
        cards.push_back(make_unique<YearOfPlenty>());
        cards.push_back(make_unique<RoadBuilding>());
        cards.push_back(make_unique<RoadBuilding>());
        cards.push_back(make_unique<VictoryPoint>());
        cards.push_back(make_unique<VictoryPoint>());
        cards.push_back(make_unique<VictoryPoint>());
        cards.push_back(make_unique<VictoryPoint>());
        cards.push_back(make_unique<VictoryPoint>());
        for (int i = 0; i < 14; ++i) {
            cards.push_back(make_unique<Knight>());
        }
        // Shuffle the devcards
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
        // Transfer ownership of shuffled cards to devcards vector
        for (auto& card : cards) {
            this->devcards.push(std::move(card));
        }
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
            if(from < 1 || from > 54 || to < 1 || to > 54){
                cout << "You are out of bounds (1-54)" << endl;
                continue;
            }
            if(!board.getSpot(from).closeTo(board.getSpot(to))){
                cout << "There's no road between " << from << " and " << to << endl;
                continue;
            }
            if(!board.getSpot(from).closeTo(board.getSpot(to))){
                cout << "There's no road between " << from << " and " << to << endl;
                continue;
            }
            if(p.getColor() != board.getSpot(from).getOwner() && p.getColor() != board.getSpot(to).getOwner()            // if p doesnt own from or to
            && (board.getSpot(from).getOwner()=="" || p.getColor() != board.getSpot(from).getOwner().replace(2, 2, "0;"))// neither has a city in from
            && (board.getSpot(to).getOwner()=="" || p.getColor() != board.getSpot(to).getOwner().replace(2, 2, "0;"))){  // or a city in to
                vector<string> roads = this->board.getSpot(from).getRoads();
                bool neighborRoad = false;
                for(unsigned int i=0; i<roads.size(); i++){
                    if(roads[i] == p.getColor()){ neighborRoad = true; }
                }
                roads = this->board.getSpot(to).getRoads();
                for(unsigned int i=0; i<roads.size(); i++){
                    if(roads[i] == p.getColor()){ neighborRoad = true; }
                }
                if(!neighborRoad){
                    cout << "Cant place a road not connected to a settlement/road" << endl; 
                    continue;
                }
            }
            p.builtRoad();
            vector<unsigned int> neighbors = this->board.getSpot(from).getNeighbors();
            bool existingRoad = false;
            for(unsigned int i=0; i<neighbors.size(); i++){
                if(board.getSpot(neighbors[i]) == board.getSpot(to)){
                    if(board.getSpot(from).getRoadOwner(i) != ""){
                        existingRoad = true;
                        break;
                    }
                    board.getSpot(from).setRoadOwner(p.getColor(), i);
                }
            }
            if(existingRoad){
                cout << "There's already a road there" << endl;
                continue;
            }
            neighbors = this->board.getSpot(to).getNeighbors();
            for(unsigned int i=0; i<neighbors.size(); i++){
                if(board.getSpot(neighbors[i]) == board.getSpot(from)){
                    board.getSpot(to).setRoadOwner(p.getColor(), i);
                }
            }
            break;
        }
        return true;
    }
    
    void Catan::printBoard(){
        this->board.printBoard();
    }

    bool Catan::gotWinner(){
        int maxRoad = 0; unsigned int maxRoadIndex = 0;
        int maxKnight = 0; unsigned int maxKnightIndex = 0;
        vector<int> points = {players[0].getPoints(),players[1].getPoints(),players[2].getPoints()};
        for(unsigned int i=0; i < players.size(); i++){
            if(players[i].getRoads() > maxRoad){ 
                maxRoad = players[i].getRoads(); 
                maxRoadIndex = i;
            }
            if(players[i].getKnights() > maxKnight){ 
                maxKnight = players[i].getKnights(); 
                maxKnightIndex = i;
            }
        }
        bool onlyMaxRoad = true; bool onlyMaxKnights = true;
        for(unsigned int i=0; i < players.size(); i++){
            if(i != maxRoadIndex && maxRoad == players[i].getRoads()){ 
                onlyMaxRoad = false;
            }
            if(i != maxKnightIndex && maxKnight == players[i].getKnights()){ 
                onlyMaxKnights = false;
            }
        }
        if(onlyMaxRoad && maxRoad != 0){  points[maxRoadIndex] += 2; }
        if(onlyMaxKnights && maxKnight >= 3){  points[maxKnightIndex] += 2; }
        
        for(unsigned int i=0; i < players.size(); i++){
            if(points[i] >= 10){
                return true;
            }
        }
        return false;
    }
   
    void Catan::buyDevelopmentCard(Player& p){
        if (this->devcards.empty()) {
            cout << "No development cards left to draw!" << endl;
            return;
        }
        if(p.getOats() > 0 && p.getWool() > 0 && p.getRock() > 0){
            unique_ptr<Devcard> card = std::move(this->devcards.top());
            devcards.pop();
            cout << "You got a " << card->getType() << "!" << endl;
            if(card->getType() == "Victory Point"){ card->playCard(p, *this); }
            else if(card->getType() == "Knight"){ p.addKnights(1); }
            else if(card->getType() == "Monopoly"){ p.addMonopoly(1); }
            else if(card->getType() == "Year of Plenty"){ p.addYearOfPlenty(1); }
            else if(card->getType() == "Road Building"){ p.addRoadBuilding(1); }
            p.addWool(-1);
            p.addRock(-1);
            p.addOats(-1);
        } else{ cout << "Not enough resources" << endl; }
    }
    void Catan::useDevelopmentCard(Player& p){
        string cardName, choice;
        cout << "what card do you wish to use? (Knight/Monopoly/Road Building/Year of Plenty)" << endl;
        cin.ignore();
        getline(cin, cardName);
        if(cardName == "0"){ return; }
        if(cardName == "Monopoly" && p.getMonopoly() > 0){
            Monopoly().playCard(p,*this);
        }
        else if(cardName == "Knight" && p.getKnights() > 0){
            Knight().playCard(p,*this);
        }
        else if(cardName == "Year of Plenty" && p.getYearOfPlenty() > 0){
            YearOfPlenty().playCard(p,*this);
        }
        else if(cardName == "Road Building" && p.getRoadBuilding() > 0){
            RoadBuilding().playCard(p,*this);
        }
        else{ cout<< "No such card" << endl; return;}
    }
}