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
        vector<Player*> players = c.getPlayers();
        cout << "Choose a resource to get (wool/wood/rock/iron/oats)" << endl;
        cin >> choice;
        for (Player* player : players) {
            if (p == *player) continue;
            if (choice == "wool") {
                p.addWool(player->getWool());
                player->addWool(-player->getWool());
            } else if (choice == "wood") {
                p.addWood(player->getWood());
                player->addWood(-player->getWood());
            } else if (choice == "rock") {
                p.addRock(player->getRock());
                player->addRock(-player->getRock());
            } else if (choice == "iron") {
                p.addIron(player->getIron());
                player->addIron(-player->getIron());
            } else if (choice == "oats") {
                p.addOats(player->getOats());
                player->addOats(-player->getOats());
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
