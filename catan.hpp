// ID: 3224653689
// MAIL: adam.sinale@gmail.com

#pragma once

#include "player.hpp"
#include "devcard.hpp"
#include "board.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <stack>

using std::stack;

namespace ariel {
    class Catan {
    private:
        vector<Player> players;
        unsigned int turn = 0;
        Board board;
        stack<string> devcards;

    public:
        Catan(Player& p1, Player& p2, Player& p3);
        ~Catan();
        vector<Player>& ChooseStartingPlayer();
        unsigned int getTurn(){ return turn; }
        int rollDice();
        void nextTurn();
        bool placeSettlement(Player& p);
        bool upgradeSettlement(Player& p);
        bool trade(Player& p);
        bool placeRoad(Player& p);
        void printBoard();
        bool gotWinner();
        void buyDevelopmentCard(Player& p);
        void useDevelopmentCard(Player& p);
    };
}
