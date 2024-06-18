// ID: 3224653689
// MAIL: adam.sinale@gmail.com

#pragma once

#include "player.hpp"
#include <iostream>
#include <string>
#include <memory>

namespace ariel {

    class Catan;  // Forward declaration to avoid circular dependencies

    // Base class Devcard
    class Devcard {
    private:
        string type;

    public:
        Devcard(string type);
        virtual ~Devcard();
        string getType() const;
        virtual void playCard(Player& p, Catan& c) = 0;  // Pure virtual function
    };

    // Derived class Knight
    class Knight : public Devcard {
    public:
        Knight();
        void playCard(Player& p, Catan& c) override;
    };

    // Derived class YearOfPlenty
    class YearOfPlenty : public Devcard {
    public:
        YearOfPlenty();
        void playCard(Player& p, Catan& c) override;
    };

    // Derived class RoadBuilding
    class RoadBuilding : public Devcard {
    public:
        RoadBuilding();
        void playCard(Player& p, Catan& c) override;
    };

    // Derived class Monopoly
    class Monopoly : public Devcard {
    public:
        Monopoly();
        void playCard(Player& p, Catan& c) override;
    };

    // Derived class VictoryPoint
    class VictoryPoint : public Devcard {
    public:
        VictoryPoint();
        void playCard(Player& p, Catan& c) override;
    };

}
