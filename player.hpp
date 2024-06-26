// ID: 3224653689
// MAIL: adam.sinale@gmail.com

#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "board.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

namespace ariel {
    class Player {
    private:
        string color;
        string name;
        int wool = 2;
        int iron = 0;
        int oats = 2;
        int wood = 4;
        int rock = 4;

        int roads = 0;
        int points = 0;

        int knights = 0;
        int monopoly = 0;
        int yearOfPlenty = 0;
        int roadBuilding = 0;

    public:
        Player();
        Player(string name, string c);
        ~Player();
        int getWood(){ return wood; }
        int getRock(){ return rock; }
        int getWool(){ return wool; }
        int getIron(){ return iron; }
        int getOats(){ return oats; }
        void addWood(int a){ wood += a; }
        void addRock(int a){ rock += a; }
        void addWool(int a){ wool += a; }
        void addIron(int a){ iron += a; }
        void addOats(int a){ oats += a; }
        void addPoint(){ points++; }
        void addMonopoly(int a){ monopoly += a; }
        void addKnights(int a){ knights += a; }
        void addYearOfPlenty(int a){ yearOfPlenty += a; }
        void addRoadBuilding(int a){ roadBuilding += a; }
        int getMonopoly(){ return monopoly; }
        int getKnights(){ return knights; }
        int getYearOfPlenty(){ return yearOfPlenty; }
        int getRoadBuilding(){ return roadBuilding; }
        string getName(){ return name; }
        string getColor(){ return color; }
        int getPoints(){ return points; }
        int getRoads(){ return roads; }
        bool trade(Player& to);
        bool tradeBank();
        void builtRoad(){ wood--; rock--; roads++; }
        void builtSettlement(){ wood--; rock--; wool--; oats--; }
        void upgradedCity(){ addOats(-2); addIron(-3); }
        void printPoints();
        bool operator==(Player other){ return this->color == other.color; }
        bool operator!=(Player other){ return !(*this == other); }
    };
}
