// ID: 3224653689
// MAIL: adam.sinale@gmail.com

#pragma once
#include "player.hpp"
#include "board.hpp"

#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

namespace ariel {
    class Catan {
    private:
        vector<vector<Player>> players;

    public:
        Catan(Player p1, Player p2, Player p3);
        static void ChooseStartingPlayer();
        static Board getBoard();
        static void printWinner();
    };
}
