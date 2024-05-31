// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include "spot.hpp"

#define FALSE 0
#define TRUE 1

const std::string RESET = "\033[0m";

namespace ariel {

    Spot::Spot(){}
    Spot::~Spot(){}

    void Spot::add_info(vector<string> type, vector<int> num, vector<int> neighbors, unsigned int id){
        this->type = type;
        this->num = num;
        this->neighbors = neighbors;
        this->id = id;
    }

    string Spot::diceInSpot(int result){
        for(unsigned int i=0; i<num.size(); i++){
            if(num[i] == result){ return type[i]; }
        }
        return "0";
    }

    std::ostream& operator<<(std::ostream& os, Spot& s) {
        string spaces = "    ";
        if(s.id < 10){ spaces = "     "; }
        os << s.owner << "("<<to_string(s.id)<<")" << RESET << spaces;
        return os;
    }
    bool Spot::operator>(Spot other){
        for(unsigned int i=0; i< this->neighbors.size(); i++){
            if(other.id == neighbors[i]){ return true; }
        }
        return false;
    }
    string Spot::getType(unsigned int place){
        string spaces = ",";
        if(num[place] < 10){ spaces = ", "; }
        return type[place] + spaces + to_string(num[place]);
    };

}