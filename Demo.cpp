/**
 * Demo file for Ex3.
a b c 52 52 49 53 53 50 54 54 51 47 47 51 46 46 50 45 45 49
a b c 52 52 49 53 53 50 54 54 51 47 47 51 46 46 50 45 45 49 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"

using namespace std;
using namespace ariel;

int main1()
{
    unsigned int choice;
    int diceSum;
    string name1,name2,name3;
    cout << "Welcome to Catan!\n Insert your names" << endl;
    cout <<"Player 1 (You're red):" << endl;
    cin >> name1;
    cout <<"Player 2 (You're yellow):" << endl;
    cin >> name2;
    cout <<"Player 3 (You're blue):" << endl;
    cin >> name3;
    Player p1(name1, "\033[0;31m");
    Player p2(name2, "\033[0;33m");
    Player p3(name3, "\033[0;34m");
    Catan catan(p1, p2, p3);
    // Starting of the game. Every player places two settlements and two roads.
    vector<Player*> players = catan.ChooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
    for(unsigned int i=0; i<=2; i++){
        catan.printBoard();
        cout <<"Place the 1st Settelment " << players[i]->getName() << endl;
        catan.placeSettlement(*players[i]);
        catan.printBoard();
        cout <<"Place the 1st road " << players[i]->getName() << endl;
        catan.placeRoad(*players[i]);
        catan.nextTurn();
    }
    catan.nextTurn();
    for(unsigned int j=3; j>0; j--){
        unsigned int i = j-1;
        catan.nextTurn();
        catan.printBoard();
        cout <<"Place the 2nd Settelment " << players[i]->getName() << endl;
        catan.placeSettlement(*players[i]);
        catan.printBoard();
        cout <<"Place the 2st road " << players[i]->getName() << endl;
        catan.placeRoad(*players[i]);
        catan.nextTurn();
    }
    catan.printBoard();
    while(!catan.gotWinner()){
        cout << "It's your turn " << players[catan.getTurn()]->getColor() << players[catan.getTurn()]->getName() << "\033[0m" << endl;
        diceSum = catan.rollDice();
        cout << "The dices rolled " << diceSum << endl;
        choice = 10;
        while(choice != 9 && !catan.gotWinner()){
            cout << "====================" << endl;
            cout << "You have: " << endl;
            cout << "Wood: " << players[catan.getTurn()]->getWood() << endl;
            cout << "Rock: " << players[catan.getTurn()]->getRock() << endl;
            cout << "Wool: " << players[catan.getTurn()]->getWool() << endl;
            cout << "Iron: " << players[catan.getTurn()]->getIron() << endl;
            cout << "Oats: " << players[catan.getTurn()]->getOats() << endl;
            cout << "--------------------" << endl;
            cout << "Points: " << players[catan.getTurn()]->getPoints() << endl;
            cout << "Knights: " << players[catan.getTurn()]->getKnights() << endl;
            cout << "Monopoly: " << players[catan.getTurn()]->getMonopoly() << endl;
            cout << "Road building: " << players[catan.getTurn()]->getRoadBuilding() << endl;
            cout << "Year of Plenty: " << players[catan.getTurn()]->getYearOfPlenty() << endl;
            cout << "====================" << endl;
            cout << "Choose your move:" << endl;
            cout << "1 - Build settlement" << endl;
            cout << "2 - Build road" << endl;
            cout << "3 - Upgrade to city" << endl;
            cout << "4 - Trade with player" << endl;
            cout << "5 - Trade with bank" << endl;
            cout << "6 - Buy development card" << endl;
            cout << "7 - Use development card" << endl;
            cout << "9 - End turn" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Where do you want to build it? (0 to regret)" << endl;
                    catan.placeSettlement(*players[catan.getTurn()]);
                    break;
                case 2:
                    cout << "Where do you want to build it? (0 to regret)" << endl;
                    catan.placeRoad(*players[catan.getTurn()]);
                    break;
                case 3:
                    cout << "Choose settlement to upgrade. (0 to regret)" << endl;
                    catan.upgradeSettlement(*players[catan.getTurn()]);
                    break;
                case 4:
                    cout << "Who do you wanna trade with? (0 to regret)" << endl;
                    catan.trade(*players[catan.getTurn()]);
                    break;
                case 5:
                    players[catan.getTurn()]->tradeBank();
                    break;
                case 6:
                    catan.buyDevelopmentCard(*players[catan.getTurn()]);
                    break;
                case 7:
                    catan.useDevelopmentCard(*players[catan.getTurn()]);
                    break;
                case 9:
                    catan.nextTurn();
                    break;
                case 0:
                    cout << "Exiting game." << endl;
                    return 0; // Exit the game loop and end the program
                default:
                    cout << "Invalid choice. Please choose a valid option." << endl;
                    break;
            }
            catan.printBoard();
        }
    }
    cout << "====================\n" << players[catan.getTurn()]->getName() << " Won!!!\n" <<"====================\n" << endl;
    return 0;
}