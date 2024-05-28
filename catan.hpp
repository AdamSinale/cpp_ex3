// ID: 3224653689
// MAIL: adam.sinale@gmail.com

#pragma once

#include "player.hpp"
#include "board.hpp"

#include <vector>
#include <iostream>
#include <string>

namespace ariel {
    class Catan {
    private:
        Player p1, p2, p3;
        Board board;

    public:
        Catan(Player p1, Player p2, Player p3);
        ~Catan();
        void ChooseStartingPlayer();
        void placeSettelemnt(Player p, unsigned int spot);
        void placeRoad(Player p, int from, int to);
        void printWinner();
    };
}
