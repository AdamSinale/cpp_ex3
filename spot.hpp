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
        vector<int> num;
        vector<Spot> neighbors;
        int owner = 0;
        
    public:
        Spot();
        ~Spot();
        void add_info(vector<string> type, vector<int> num, vector<Spot> neighbors);
        void setOwner(int p){ if(this->owner==0){this->owner == p;}};
        void printSpot();
        friend std::ostream& operator<<(std::ostream& os, Spot& g);
    };
}
