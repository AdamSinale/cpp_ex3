// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include "spot.hpp"

#define FALSE 0
#define TRUE 1

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string RESET = "\033[0m";

namespace ariel {

    Spot::Spot(){}
    Spot::~Spot(){}

    void Spot::add_info(vector<string> type, vector<int> num, vector<Spot> neigbors){
        this->neighbors = neighbors;
        this->type = type;
        this->num = num;
    }
    
    std::ostream& operator<<(std::ostream& os, Spot& g) {
        os << RED << "X" << RESET;
        return os;
    }
}