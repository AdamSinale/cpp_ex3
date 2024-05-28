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
        string owner = "";
        
    public:
        Spot();
        ~Spot();
        void add_info(vector<string> type, vector<int> num, vector<Spot> neighbors);
        void setOwner(string color){ if(this->owner.length() == 0){this->owner = color;} };
        friend std::ostream& operator<<(std::ostream& os, Spot& g);
    };
}
