// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include "catan.hpp"

#define FALSE 0
#define TRUE 1

namespace ariel {

    Catan::Catan(Player pl1, Player pl2, Player pl3){
        this->players = {pl1,pl2,pl3};
        board = Board();
        this->board.printBoard();
    }
    Catan::~Catan(){}
    
    void Catan::ChooseStartingPlayer(){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(players.begin(), players.end(), std::default_random_engine(seed));
        this->turn = 0;
        cout << "The starting player is " << players[turn].getName() << "\n" << endl;
    }
    void Catan::nextTurn(){
        this->turn = (this->turn + 1) % 3;
        cout << "It's your turn now " << players[turn].getName() << "\n" << endl;
    }
    void Catan::placeSettelemnt(Player p, unsigned int spot){
        if(players[turn] != p){
            throw std::invalid_argument("Wait your turn " + p.getName() + ",\n"
                 + "It's your turn " + players[turn].getName() + "\n");
        }
        board.setOwner(spot, p.getColor());
        this->board.printBoard();
    }
    void Catan::placeRoad(Player p, int from, int to){

    }
    void Catan::printWinner(){

    }
}