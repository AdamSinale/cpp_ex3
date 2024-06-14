// ID: 3224653689
// MAIL: adam.sinale@gmail.com

#pragma once

#include "player.hpp"
#include "board.hpp"

#include <vector>
#include <iostream>
#include <string>

namespace ariel {
    class Devcard {
    private:
        string type;

    public:
        Devcard(string type);
        ~Devcard();
        void playCard(Player& p);
    };
}
