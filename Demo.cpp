/**
 * Demo file for Ex3.
 *
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
    unsigned int spot1, spot2, choise;
    for(unsigned int i=0; i<=2; i++){
        cout <<"Place the 1st Settelment " << players[i].getName() << endl;
        cin >> spot1;
        catan.placeSettelemnt(players[i], spot1);
        cout <<"Place the 1st road " << players[i].getName() << endl;
        cin >> spot1;
        cin >> spot2;
        while(!catan.placeRoad(players[i], spot1, spot2)){
            cout << "Try again" << endl;
            cin >> spot1;
            cin >> spot2;
        };
        catan.nextTurn();
    }
    catan.nextTurn();
    for(unsigned int i=2; i>=0; i--){
        catan.nextTurn();
        cout <<"Place the 2nd Settelment " << players[i].getName() << endl;
        cin >> spot1;
        catan.placeSettelemnt(players[i], spot1);
        cout <<"Place the 2st road " << players[i].getName() << endl;
        cin >> spot1;
        cin >> spot2;
        while(!catan.placeRoad(players[i], spot1, spot2)){
            cout << "Try again" << endl;
            cin >> spot1;
            cin >> spot2;
        };
        catan.nextTurn();
    }
    while(!catan.gotWinner()){
        cout << "It's your turn" << players[catan.getTurn()].getName() << ", chose your move:" << endl;
        cout << "Build settlement" << endl;
        cout << "Build road" << endl;
        cin >> choise;
        catan.nextTurn();
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