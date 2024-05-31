// ID: 3224653689
// MAIL: adam.sinale@gmail.com

#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "board.hpp"

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

namespace ariel {
    class Player {
    private:
        string color;
        string name;
        int wood = 2;
        int wool = 0;
        int iron = 0;
        int wheat = 0;
        int rock = 2;

        int points = 0;


    public:
        Player();
        Player(string name, string c);
        ~Player();
        int getWood(){ return wood; }
        int getRock(){ return rock; }
        string getName(){ return name; }
        string getColor(){ return color; }
        int getPoints(){ return points; }
        void rollDice();
        void endTurn();
        void trade(Player to, string give, string get, int amount_give, int amount_get);
        void buyDevelopmentCard();
        void builtRoad(){ wood--; rock--; }
        void printPoints();
        bool operator==(Player other){ return this->color == other.color; }
        bool operator!=(Player other){ return !(*this == other); }
    };
}
