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
#include <memory>
#include <random>
#include <chrono>
#include <algorithm>

using std::stack;
using std::unique_ptr;

namespace ariel {
    class Catan {
    private:
        vector<Player*> players;
        unsigned int turn = 0;
        Board board;
        stack<unique_ptr<Devcard>> devcards; 

    public:
        Catan(Player& p1, Player& p2, Player& p3);
        ~Catan();
        vector<Player*> ChooseStartingPlayer();
        vector<Player*> getPlayers(){ return this->players; }
        unsigned int getTurn(){ return turn; }
        int rollDice();
        void nextTurn();
        bool placeSettlement(Player& p);
        bool upgradeSettlement(Player& p);
        bool trade(Player& p);
        bool placeRoad(Player& p);
        void printBoard();
        bool gotWinner();
        bool buyDevelopmentCard(Player& p);
        void useDevelopmentCard(Player& p);
    };
}
