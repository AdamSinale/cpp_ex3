// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "devcard.hpp"
#include "spot.hpp"
#include <sstream>
#include "doctest.hpp"

using namespace std;
using namespace ariel;

std::streambuf *orig = std::cout.rdbuf(); // save original buffer

void suppressOutput()
{
    std::cout.rdbuf(NULL);
}

void restoreOutput()
{
    std::cout.rdbuf(orig);
}

TEST_CASE("Test starting player")
{
    Player p1("a", "\033[0;31m");
    Player p2("b", "\033[0;33m");
    Player p3("c", "\033[0;34m");
    ariel::Catan catan(p1, p2, p3);
    vector<string> names = {"a", "b", "c"};
    vector<vector<string>> possible_orders = {
        {"a", "b", "c"},
        {"a", "c", "b"},
        {"b", "a", "c"},
        {"b", "c", "a"},
        {"c", "b", "a"},
        {"c", "a", "b"}
    };
    vector<Player*> ps = catan.ChooseStartingPlayer();
    vector<string> result_names;
    for (const auto& player : ps) {
        result_names.push_back(player->getName());
    }
    bool valid_order = false;
    for (const auto& order : possible_orders) {
        if (result_names == order) {
            valid_order = true;
            break;
        }
    }
    CHECK(valid_order);
}
TEST_CASE("Test player name")
{
    Player p1("a", "\033[0;31m");
    CHECK(p1.getName() == "a");
}
TEST_CASE("Test player building")
{
    Player p1("a", "\033[0;31m");    // started with enough resources for 2 of each
    p1.builtRoad();
    p1.builtRoad();
    p1.builtSettlement();
    p1.builtSettlement();
    CHECK(p1.getWood() == 0);
    CHECK(p1.getRock() == 0);
    CHECK(p1.getWool() == 0);
    CHECK(p1.getIron() == 0);
    CHECK(p1.getOats() == 0);
    p1.upgradedCity();          // dont worry, won't get here with not enough resources
    CHECK(p1.getIron() == -3);
    CHECK(p1.getOats() == -2);
}

TEST_CASE("Test player resources")
{
    Player p1("a", "\033[0;31m");
    p1.addWood(1);
    p1.addRock(1);
    p1.addWool(3);
    p1.addIron(5);
    p1.addOats(3);
    p1.addPoint();
    p1.addMonopoly(1);
    p1.addKnights(1);
    p1.addYearOfPlenty(1);
    p1.addRoadBuilding(1);
    CHECK(p1.getWood() == 5);
    CHECK(p1.getRock() == 5);
    CHECK(p1.getWool() == 5);
    CHECK(p1.getIron() == 5);
    CHECK(p1.getOats() == 5);
    CHECK(p1.getPoints() == 1);
    CHECK(p1.getMonopoly() == 1);
    CHECK(p1.getKnights() == 1);
    CHECK(p1.getYearOfPlenty() == 1);
    CHECK(p1.getRoadBuilding() == 1);
}

TEST_CASE("Test player trade")
{
    Player p1("a", "\033[0;31m");
    Player p2("b", "\033[0;33m");

    p1.addRock(6); // fill to 10
    p2.addWool(8); // fill to 10
    p2.addRock(-4); // set to 0
    p1.addWool(-2); // set to 0
    CHECK(p1.getRock() == 10);
    CHECK(p2.getRock() == 0);
    CHECK(p1.getWool() == 0);
    CHECK(p2.getWool() == 10);

    std::istringstream input("0\n0\n0\n10\n0\n10\n0\n0\n0\n0\ny\n");  
    std::cin.rdbuf(input.rdbuf());
    suppressOutput();
    bool trade_result = p1.trade(p2); // testing p2-10 wool for p1-10 rock
    restoreOutput();

    CHECK(trade_result == true);
    CHECK(p1.getRock() == 0);
    CHECK(p2.getRock() == 10);
    CHECK(p1.getWool() == 10);
    CHECK(p2.getWool() == 0);
}

TEST_CASE("Test player trade failure due to insufficient resources")
{
    Player p1("a", "\033[0;31m");
    Player p2("b", "\033[0;33m");

    p1.addRock(6); // fill to 10
    p2.addWool(8); // fill to 10
    p2.addRock(-4); // set to 0
    p1.addWool(-2); // set to 0

    std::istringstream input("0\n0\n0\n11\n0\n10\n0\n0\n0\n0\ny\n");  
    std::cin.rdbuf(input.rdbuf());
    suppressOutput();
    bool trade_result = p1.trade(p2); // testing p2-10 wool for p1-11 rock
    restoreOutput();

    CHECK(trade_result == false);
    CHECK(p1.getRock() == 10);
    CHECK(p2.getRock() == 0);
    CHECK(p1.getWool() == 0);
    CHECK(p2.getWool() == 10);
}

TEST_CASE("Test player trade with bank")
{
    Player p1("a", "\033[0;31m");

    p1.addWood(6); // fill to 10

    std::istringstream input("0\n8\n0\n0\n0\n0\n0\n2\n0\n0\n");
    std::cin.rdbuf(input.rdbuf());
    suppressOutput();
    bool trade_result = p1.tradeBank();
    restoreOutput();

    CHECK(trade_result == true);
    CHECK(p1.getWood() == 2);
    CHECK(p1.getIron() == 2);
}

TEST_CASE("Test player trade with bank incorrect amounts")
{
    Player p1("a", "\033[0;31m");

    p1.addWood(6); // fill to 10

    std::istringstream input("0\n9\n0\n0\n0\n0\n0\n2\n0\n0\n");
    std::cin.rdbuf(input.rdbuf());
    suppressOutput();
    bool trade_result = p1.tradeBank();
    restoreOutput();

    CHECK(trade_result == false);
    CHECK(p1.getWood() == 10);
    CHECK(p1.getIron() == 0);
}

TEST_CASE("Test player trade with bank not enough")
{
    Player p1("a", "\033[0;31m");

    p1.addWood(6); // fill to 10

    std::istringstream input("0\n12\n0\n0\n0\n0\n0\n3\n0\n0\n");
    std::cin.rdbuf(input.rdbuf());
    suppressOutput();
    bool trade_result = p1.tradeBank();
    restoreOutput();

    CHECK(trade_result == false);
    CHECK(p1.getWood() == 10);
    CHECK(p1.getIron() == 0);
}


TEST_CASE("Test spot")
{   
    Spot sp = Spot();
    Spot spN = Spot();
    Spot spD = Spot();
    sp.add_info({"Rock"}, {9}, {2}, 1);  // spN is neighbor and 2 is its id
    spN.add_info({"Wood"}, {8}, {1}, 2); 
    spD.add_info({"Wood"}, {8}, {2}, 3); 
    CHECK(sp.getOwner() == "");
    sp.setOwner("color");                 // color is the color of the player, its his id
    CHECK(sp.getOwner() == "color");
    CHECK(sp.getType(0) == "Rock, 9");    // every spot has few resources, get 1st
    CHECK(sp.diceInSpot(9) == "Rock");    // for dice result
    CHECK(sp.closeTo(spN) == true);
    CHECK(sp.closeTo(spD) == false);
}


TEST_CASE("Test devcard")
{   
    Player p1("a", "\033[0;31m");
    Player p2("b", "\033[0;33m");
    Player p3("c", "\033[0;34m");
    Catan catan(p1, p2, p3);
    
    // RoadBuilding is basically 2 road buildings

    Monopoly monopoly = Monopoly(); 
    std::istringstream inputm("wool\n");  // same for all
    std::cin.rdbuf(inputm.rdbuf());
    suppressOutput();
    monopoly.playCard(p1, catan);
    restoreOutput();
    CHECK(p1.getWool() == 6);
    CHECK(p2.getWool() == 0);
    CHECK(p3.getWool() == 0);

    YearOfPlenty yop = YearOfPlenty();
    std::istringstream inputy("iron\n");  // same for all
    std::cin.rdbuf(inputy.rdbuf());
    suppressOutput();
    yop.playCard(p1, catan);
    restoreOutput();
    CHECK(p1.getIron() == 2);

    Knight knight = Knight(); 
    CHECK(p1.getKnights() == 0);
    knight.playCard(p1, catan);  // all it does is add knight to p1 for maybe 2 winning points
    CHECK(p1.getKnights() == 1);

    VictoryPoint victoryPoint = VictoryPoint();
    CHECK(p1.getPoints() == 0);
    victoryPoint.playCard(p1, catan);  // all it does is add knight to p1 for maybe 2 winning points
    CHECK(p1.getPoints() == 1);
}

TEST_CASE("Test building settlments and roads")
{ 
    Player p1("a", "\033[0;31m");
    Player p2("b", "\033[0;33m");
    Player p3("c", "\033[0;34m");
    Catan catan(p1, p2, p3);
    
    std::istringstream input1("55\n-1\n0\n");  // out of bounds not allowed
    std::cin.rdbuf(input1.rdbuf());
    suppressOutput();
    bool placed = catan.placeSettlement(p1);
    restoreOutput();
    CHECK(placed == false);

    std::istringstream input2("53\n");         // worked
    std::cin.rdbuf(input2.rdbuf());
    suppressOutput();
    placed = catan.placeSettlement(p1);
    restoreOutput();
    CHECK(placed == true);

    std::istringstream input3("53\n0\n");     // couldnt same place twice
    std::cin.rdbuf(input3.rdbuf());
    suppressOutput();
    placed = catan.placeSettlement(p1);
    restoreOutput();
    CHECK(placed == false);

    std::istringstream input4("50\n0\n");     // couldnt neighbor place twice
    std::cin.rdbuf(input4.rdbuf());
    suppressOutput();
    placed = catan.placeSettlement(p1);
    restoreOutput();
    CHECK(placed == false);

    std::istringstream input5("46\n");     // far enough place
    std::cin.rdbuf(input5.rdbuf());
    suppressOutput();
    placed = catan.placeSettlement(p1);
    restoreOutput();
    CHECK(placed == true);

    suppressOutput();                   // no resources anymore
    placed = catan.placeSettlement(p1);
    restoreOutput();
    CHECK(placed == false);

    suppressOutput();                   // no resources anymore
    placed = catan.upgradeSettlement(p1);
    restoreOutput();
    CHECK(placed == false);
    p1.addIron(100);
    p1.addOats(100);
    std::istringstream input6("46\n");  
    std::cin.rdbuf(input6.rdbuf());
    suppressOutput();                   // good
    placed = catan.upgradeSettlement(p1);
    restoreOutput();
    CHECK(placed == true);

    std::istringstream input7("55\n45\n46\n0\n"); 
    std::cin.rdbuf(input7.rdbuf());
    suppressOutput();                   // out of bounds/ not yours/ already upgraded
    placed = catan.upgradeSettlement(p1);
    restoreOutput();
    CHECK(placed == false);

    std::istringstream input8("55 54\n1 2\n53 54\n0 1\n"); 
    std::cin.rdbuf(input8.rdbuf());
    suppressOutput();                   // out of bounds/ not yours/ not a road/ already upgraded
    placed = catan.placeRoad(p1);
    restoreOutput();
    CHECK(placed == false);

    std::istringstream input9("53 50\n"); 
    std::cin.rdbuf(input9.rdbuf());
    suppressOutput();                  //near a settlement
    placed = catan.placeRoad(p1);
    restoreOutput();
    CHECK(placed == true);

    std::istringstream input10("54 50\n"); 
    std::cin.rdbuf(input10.rdbuf());
    suppressOutput();                  //near a road
    placed = catan.placeRoad(p1);
    restoreOutput();
    CHECK(placed == true);

    std::istringstream input11("46 50\n"); 
    std::cin.rdbuf(input11.rdbuf());
    suppressOutput();                  // no resources
    placed = catan.placeRoad(p1);
    restoreOutput();
    CHECK(placed == false);
}

TEST_CASE("Test buying cards"){
    Player p1("a", "\033[0;31m");
    Player p2("b", "\033[0;33m");
    Player p3("c", "\033[0;34m");
    Catan catan(p1, p2, p3);
    CHECK(catan.buyDevelopmentCard(p1) == true);   // in game he wont have ennough resources from start
    CHECK(p1.getPoints()+p1.getKnights()+p1.getYearOfPlenty()+p1.getMonopoly()+p1.getRoadBuilding() == 1); // added card
    p1.addOats(-1);
    CHECK(catan.buyDevelopmentCard(p1) == false);  // not enough
    CHECK(p1.getPoints()+p1.getKnights()+p1.getYearOfPlenty()+p1.getMonopoly()+p1.getRoadBuilding() == 1); // not added card
}

// 52 52 49 53 53 50 54 54 51 47 47 51 46 46 50 45 45 49