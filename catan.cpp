// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include "catan.hpp"

#define FALSE 0
#define TRUE 1

namespace ariel {

    Catan::Catan(Player pl1, Player pl2, Player pl3): p1(pl1), p2(pl2), p3(pl3), board(Board()) {}
    Catan::~Catan(){}
    
    void Catan::ChooseStartingPlayer(){
        cout << "The stating player is " << p1.getName() << endl;
    }
    void Catan::placeSettelemnt(Player p, unsigned int spot){
        if(p == p1){
            board.setOwner(spot, 1);
        } else if(p == p2){
            board.setOwner(spot, 2);
        } else if(p == p3){
            board.setOwner(spot, 3);
        }
    }
    void Catan::placeRoad(Player p, int from, int to){

    }
    void Catan::printWinner(){

    }
}