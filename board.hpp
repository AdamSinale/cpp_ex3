// ID: 3224653689
// MAIL: adam.sinale@gmail.com

#pragma once

#include "spot.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine
#include <chrono> 

using std::cout;
using std::endl;
using std::to_string;
using std::vector;
using std::string;

namespace ariel {
    class Board {
    private:
        vector<Spot> spots;

    public:
        Board();
        ~Board();
        void setOwner(unsigned int spot, string color){ this->spots[spot].setOwner(color); };
        void printBoard();
    };
}