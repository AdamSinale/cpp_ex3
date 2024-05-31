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
    
    vector<Player> Catan::ChooseStartingPlayer(){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(players.begin(), players.end(), std::default_random_engine(seed));
        this->turn = 0;
        cout << "The starting player is " << players[turn].getName() << "\n" << endl;
        return players;
    }
    
    void Catan::nextTurn(){
        this->turn = (this->turn + 1) % 3;
        cout << "It's your turn now " << players[turn].getName() << "\n" << endl;
    }
    
    bool Catan::placeSettelemnt(Player p, unsigned int spot){
        if(players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn].getName() << endl;
            return false;
        }
        board.setOwner(spot-1, p.getColor());
        this->board.printBoard();
    }
    
    bool Catan::placeRoad(Player p, unsigned int from, unsigned int to){
        if(players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn].getName() << endl;
            return false;
        }
        if(from > 0 && from < 55 && to > 0 && to < 55){
            if(p.getColor() == board.getSlot(from).getOwner() || p.getColor() == board.getSlot(to).getOwner()){
                if(board.getSlot(from)>board.getSlot(to)){
                    if(p.getWood()> 0 && p.getRock() > 0){
                        p.builtRoad();
                        this->board.printBoard();
                        // board.getSlot(from); add to spot
                        return true;
                    } else{ cout<< "not enough resources" << endl; }
                } else{ cout << "There's no road between " << to_string(from) << " and " << to_string(to) << endl; }
            } else{ cout << "Cant place a road not connected to a settlement" << endl; }
        } else{ cout << "You are out of bounds (1-54)" << endl; }
        return false;
    }
    
    bool Catan::gotWinner(){
        for(int i=0; i< players.size(); i++){
            if(players[i].getPoints() == 10){
                cout << "====================\n" << players[i].getName() << "Won!!!" <<"====================\n" << endl;
                return true;
            }
        }
        return false;
    }
}