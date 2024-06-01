/**
 * Demo file for Ex3.
a b c 52 52 49 53 53 50 54 54 51 47 47 51 46 46 50 45 45 49
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
using namespace std;
using namespace ariel;

int main()
{
    unsigned int spot1, spot2, choise;
    int diceSum;
    string name1,name2,name3;
    cout << "Welcome to Catan!\n Insert your names" << endl;
    cout <<"Player 1 (You're red):" << endl;
    cin >> name1;
    cout <<"Player 2 (You're blue):" << endl;
    cin >> name2;
    cout <<"Player 3 (You're yellow):" << endl;
    cin >> name3;
    Player p1(name1, "\033[31m");
    Player p2(name2, "\033[36m");
    Player p3(name3, "\033[33m");
    Catan catan(p1, p2, p3);
    // Starting of the game. Every player places two settlements and two roads.
    vector<Player> players = catan.ChooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
    for(unsigned int i=0; i<=2; i++){
        cout <<"Place the 1st Settelment " << players[i].getName() << endl;
        catan.placeSettelemnt(players[i]);
        cout <<"Place the 1st road " << players[i].getName() << endl;
        catan.placeRoad(players[i]);
        catan.nextTurn();
    }
    catan.nextTurn();
    for(unsigned int j=3; j>0; j--){
        unsigned int i = j-1;
        catan.nextTurn();
        cout <<"Place the 2nd Settelment " << players[i].getName() << endl;
        catan.placeSettelemnt(players[i]);
        cout <<"Place the 2st road " << players[i].getName() << endl;
        catan.placeRoad(players[i]);
        catan.nextTurn();
    }
    while(!catan.gotWinner()){
        cout << "It's your turn " << players[catan.getTurn()].getName() << endl;
        diceSum = catan.rollDice();
        cout << "The dices rolled " << diceSum << endl;
        cout << "====================" << endl;
        cout << "You have: " << endl;
        cout << "Wood: " << players[catan.getTurn()].getWood() << endl;
        cout << "Rock: " << players[catan.getTurn()].getRock() << endl;
        cout << "Wool: " << players[catan.getTurn()].getWool() << endl;
        cout << "Iron: " << players[catan.getTurn()].getIron() << endl;
        cout << "Oats: " << players[catan.getTurn()].getOats() << endl;
        cout << "====================" << endl;
        cout << "Choose your move:" << endl;
        cout << "1 - Build settlement" << endl;
        cout << "2 - Build road" << endl;

        cout << "9 - End turn" << endl;
        cin >> choise;
        if(choise == 1){
            cout<< "Where do you want to built it?" << endl;
            catan.placeSettelemnt(players[catan.getTurn()]);
        }
        if(choise == 2){
            cout<< "Where do you want to built it?" << endl;
            catan.placeRoad(players[catan.getTurn()]);
        }
        
        if(choise == 9){ catan.nextTurn(); }
    }
    // p1.rollDice();                                    // Lets say it's print 4. Then, p2 gets ore from the mountations.
    // catan.placeRoad(p1, {"Forest", "Hills"}, {5, 6}); // p1 continues to build a road.

    // p2.rollDice(); // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.

    // p3.rollDice(); // Lets say it's print 3. Then, p3 gets wheat from the Agricultural Land and Ore from the Mountains, p1 gets wheat from the Agricultural Land.

    // try
    // {
    //     p2.rollDice(); // p2 tries to roll the dice again, but it's not his turn.
    // }
    // catch (const std::exception &e)
    // {
    //     cout << e.what() << endl;
    // }

    // p1.rollDice();                       // Lets say it's print 6. Then, p1 gets bricks from the hills.
    // p1.trade(p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.

    // p2.rollDice();           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    // p2.buyDevelopmentCard(); // p2 buys a development card. Lets say it is a bonus points card.

    // p1.printPoints(); // p1 has 2 points because it has two settelments.
    // p2.printPoints(); // p2 has 3 points because it has two settelments and a bonus points card.
    // p3.printPoints(); // p3 has 2 points because it has two settelments.

    // catan.printWinner(); // Should print None because no player reached 10 points.
}