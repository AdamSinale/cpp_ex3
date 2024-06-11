// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include "player.hpp"

#define FALSE 0
#define TRUE 1

namespace ariel {

    Player::Player() {}
    Player::~Player() {}
    
    Player::Player(string name, string c) : name(name), color(c) {}
    
    void Player::endTurn(){

    }
    bool Player::trade(Player& to){
        char choice;
        int f_wool, f_wood, f_iron, f_rock, f_oats, t_wool, t_wood, t_iron, t_rock, t_oats;
        cout << "How many wool you want to give?" << endl; cin >> f_wool;
        cout << "How many wood you want to give?" << endl; cin >> f_wood;
        cout << "How many iron you want to give?" << endl; cin >> f_iron;
        cout << "How many rock you want to give?" << endl; cin >> f_rock;
        cout << "How many oats you want to give?" << endl; cin >> f_oats;
        cout << "How many wool you want to get?" << endl; cin >> t_wool;
        cout << "How many wood you want to get?" << endl; cin >> t_wood;
        cout << "How many iron you want to get?" << endl; cin >> t_iron;
        cout << "How many rock you want to get?" << endl; cin >> t_rock;
        cout << "How many oats you want to get?" << endl; cin >> t_oats;
        if(f_wool>this->wool || f_wood>this->wood || f_iron>this->iron || f_rock>this->rock || f_oats>this->oats
        || t_wool>to.getWool() || t_wool>to.getWood() || t_wool>to.getIron() || t_wool>to.getRock() || t_wool>to.getOats()){
            return false;
        }
        cout << to.getColor() << to.getName() << "\033[0m" << ", do you want to give " << t_wool << " wool, " << t_wood << " wood, " << t_iron << " iron, " << t_rock << " rock, " << t_oats << " oats for "
        << f_wool << " wool, " << f_wood << " wood, " << f_iron << " iron, " << f_rock << " rock, " << f_oats << " oats? y/n" << endl;
        cin >> choice;
        if(choice == 'y'){ 
            addWool(t_wool-f_wool); to.addWool(f_wool-t_wool);
            addWood(t_wood-f_wood); to.addWood(f_wood-t_wood);
            addIron(t_iron-f_iron); to.addIron(f_iron-t_iron);
            addRock(t_rock-f_rock); to.addRock(f_rock-t_rock);
            addOats(t_oats-f_oats); to.addOats(f_oats-t_oats);
            return true;
        }
        return false;
    }
    
    bool Player::tradeBank(){
        char choice;
        int f_wool, f_wood, f_iron, f_rock, f_oats, t_wool, t_wood, t_iron, t_rock, t_oats;
        cout << "How many wool you want to give?" << endl; cin >> f_wool;
        cout << "How many wood you want to give?" << endl; cin >> f_wood;
        cout << "How many iron you want to give?" << endl; cin >> f_iron;
        cout << "How many rock you want to give?" << endl; cin >> f_rock;
        cout << "How many oats you want to give?" << endl; cin >> f_oats;
        cout << "How many wool you want to get?" << endl; cin >> t_wool;
        cout << "How many wood you want to get?" << endl; cin >> t_wood;
        cout << "How many iron you want to get?" << endl; cin >> t_iron;
        cout << "How many rock you want to get?" << endl; cin >> t_rock;
        cout << "How many oats you want to get?" << endl; cin >> t_oats;
        int total_give = f_wool + f_wood + f_iron + f_rock + f_oats;
        int total_get = t_wool + t_wood + t_iron + t_rock + t_oats;
        if(f_wool>this->wool || f_wood>this->wood || f_iron>this->iron || f_rock>this->rock || f_oats>this->oats){
            cout << "not enough of a material" << endl;
            return false;
        }
        if(total_give % 4 != 0){
            cout << "give an amount divisible by 4" << endl;
            return false;
        }
        if(total_give/4!=total_get){
            cout << "amount to give doesnt match amount to get" << endl;
            return false;
        }
        addWool(t_wool-f_wool);
        addWood(t_wood-f_wood);
        addIron(t_iron-f_iron);
        addRock(t_rock-f_rock);
        addOats(t_oats-f_oats);
        return true;
    }
    
    void Player::buyDevelopmentCard(){
            
    }
    void Player::printPoints(){
            
    }
}