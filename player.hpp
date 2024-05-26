// ID: 3224653689
// MAIL: adam.sinale@gmail.com

#pragma once

#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

namespace ariel {
    class Player {
    private:
        string name;

    public:
        Player(string name);
        static void placeSettelemnt(vector<string> places, vector<int> placesNum, Board board);
        static void placeRoad(vector<string> places, vector<int> placesNum, Board board);
        static void rollDice();
        static void endTurn();
        static void trade(Player to, string give, string get, int amount_give, int amount_get);
        static void buyDevelopmentCard();
        static void printPoints();
    };
}
