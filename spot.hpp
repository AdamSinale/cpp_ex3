// ID: 3224653689
// MAIL: adam.sinale@gmail.com

#pragma once

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::to_string;
using std::vector;
using std::string;

namespace ariel {
    class Spot {
    private:
        vector<string> type;
        vector<unsigned int> num;
        vector<unsigned int> neighbors;
        string owner = "";
        unsigned int id;
        
    public:
        Spot();
        ~Spot();
        vector<unsigned int> getNeighbors(){ return neighbors; }
        void add_info(vector<string> type, vector<unsigned int> num, vector<unsigned int> neighbors, unsigned int id);
        void setOwner(string color){ if(this->owner.length() == 0){this->owner = color;} };
        string getOwner(){ return this->owner; };
        string diceInSpot(int result);
        friend std::ostream& operator<<(std::ostream& os, Spot& s);
        // bool operator==(Spot other){ return (*this).id == other.id; };
        bool closeTo(Spot other);
        string getType(unsigned int place);
    };
}
