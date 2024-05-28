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
        int wood = 0;
        int wool = 0;
        int iron = 0;
        int wheat = 0;
        int stone = 0;


    public:
        Player();
        Player(string name, string c);
        ~Player();
        string getName(){ return name; }
        string getColor(){ return color; }
        void rollDice();
        void endTurn();
        void trade(Player to, string give, string get, int amount_give, int amount_get);
        void buyDevelopmentCard();
        void printPoints();
        bool operator==(Player other){ return this->color == other.color; }
        bool operator!=(Player other){ return !(*this == other); }
    };
}
