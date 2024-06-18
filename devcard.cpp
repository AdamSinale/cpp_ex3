#include "devcard.hpp"
#include "catan.hpp"
#include <iostream>

namespace ariel {

    // Implementation of Devcard
    Devcard::Devcard(string type) : type(type) {}
    Devcard::~Devcard() {}
    string Devcard::getType() const { return type; }

    // Implementation of Knight
    Knight::Knight() : Devcard("Knight") {}
    void Knight::playCard(Player& p, Catan& c) {
        p.addKnights(1);
        cout << "Knight added." << endl;
    }

    // Implementation of YearOfPlenty
    YearOfPlenty::YearOfPlenty() : Devcard("Year of Plenty") {}
    void YearOfPlenty::playCard(Player& p, Catan& c) {
        string choice;
        cout << "Choose a resource to get (wool/wood/rock/iron/oats)" << endl;
        cin >> choice;
        if(choice == "wool"){ p.addWool(2); }
        else if(choice == "wood"){ p.addWood(2); }
        else if(choice == "rock"){ p.addRock(2); }
        else if(choice == "iron"){ p.addIron(2); }
        else if(choice == "oats"){ p.addOats(2); }
        p.addYearOfPlenty(-1);
    }

    // Implementation of RoadBuilding
    RoadBuilding::RoadBuilding() : Devcard("Road Building") {}
    void RoadBuilding::playCard(Player& p, Catan& c) {
        p.addWood(2); p.addRock(2);
        cout << "1st road" << endl;
        if(!c.placeRoad(p)){ p.addWood(-2); p.addRock(-2); return; }
        cout << "2nd road" << endl;
        while(!c.placeRoad(p)){ cout << "Can't regret building a 2nd road now" << endl; }
        p.addRoadBuilding(-1);
    }

    // Implementation of Monopoly
    Monopoly::Monopoly() : Devcard("Monopoly") {}
    void Monopoly::playCard(Player& p, Catan& c) {
        string choice;
        vector<Player> players = c.getPlayers();
        cout << "Choose a resource to get (wool/wood/rock/iron/oats)" << endl;
        cin >> choice;
        for(unsigned int i=0; i<players.size(); i++){
            if(p == players[i]){ continue; }
            if(choice == "wool"){
                p.addWool(players[i].getWool());
                players[i].addWool(-players[i].getWool());
            }else if(choice == "wood"){
                p.addWood(players[i].getWood());
                players[i].addWood(-players[i].getWood());
            }else if(choice == "rock"){
                p.addRock(players[i].getRock());
                players[i].addRock(-players[i].getRock());
            }else if(choice == "iron"){
                p.addIron(players[i].getIron());
                players[i].addIron(-players[i].getIron());
            }else if(choice == "oats"){
                p.addOats(players[i].getOats());
                players[i].addOats(-players[i].getOats());
            }
        }
        p.addMonopoly(-1);
    }

    // Implementation of VictoryPoint
    VictoryPoint::VictoryPoint() : Devcard("Victory Point") {}
    void VictoryPoint::playCard(Player& p, Catan& c) {
        p.addPoint();
        cout << "Point added" << endl;
    }

}
