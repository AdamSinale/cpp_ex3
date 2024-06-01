// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include "board.hpp"


#define FALSE 0
#define TRUE 1

namespace ariel {

    Board::Board(){
        spots = {Spot(),Spot(),Spot(),
             Spot(),Spot(),Spot(),Spot(),
             Spot(),Spot(),Spot(),Spot(),
          Spot(),Spot(),Spot(),Spot(),Spot(),
          Spot(),Spot(),Spot(),Spot(),Spot(),
       Spot(),Spot(),Spot(),Spot(),Spot(),Spot(),
       Spot(),Spot(),Spot(),Spot(),Spot(),Spot(),
          Spot(),Spot(),Spot(),Spot(),Spot(),
          Spot(),Spot(),Spot(),Spot(),Spot(),
             Spot(),Spot(),Spot(),Spot(),
             Spot(),Spot(),Spot(),Spot(),
                 Spot(),Spot(),Spot()};
        vector<unsigned int> nums = {5,2,6,3,8,10,9,12,11,4,8,10,9,4,5,6,3,11,9,7};
        vector<string> types = {"Wood","Wood","Wood","Wood",
                                "Oats","Oats","Oats","Oats",
                                "Rock","Rock","Rock","Rock",
                                "Iron","Iron","Iron",
                                "Wool","Wool","Wool"};
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(types.begin(), types.end(), std::default_random_engine(seed));

        spots[0].add_info({types[0]}, {nums[0]}, {4,5}, 1);
        spots[1].add_info({types[1]}, {nums[1]}, {5,6}, 2);
        spots[2].add_info({types[2]}, {nums[2]}, {6,7}, 3);

        spots[3].add_info({types[0]}, {nums[0]}, {1,8}, 4);
        spots[4].add_info({types[0],types[1]}, {nums[0],nums[1]}, {1,2,9}, 5);
        spots[5].add_info({types[1],types[2]}, {nums[1],nums[2]}, {2,3,10}, 6);
        spots[6].add_info({types[2]}, {nums[2]}, {3,11}, 7);

        spots[7].add_info({types[0],types[11]}, {nums[0],nums[11]}, {4,12,13}, 8);
        spots[8].add_info({types[0],types[1],types[12]}, {nums[0],nums[1],nums[12]}, {13,14,5}, 9);
        spots[9].add_info({types[1],types[2],types[13]}, {nums[1],nums[2],nums[13]}, {14,15,6}, 10);
        spots[10].add_info({types[2],types[3]}, {nums[2],nums[3]}, {15,16,7}, 11);
        
        spots[11].add_info({types[11]}, {nums[11]}, {8,17}, 12);
        spots[12].add_info({types[0],types[11],types[12]}, {nums[0],nums[11],nums[12]}, {8,9,18}, 13);
        spots[13].add_info({types[1],types[12],types[13]}, {nums[1],nums[12],nums[13]}, {9,10,19}, 14);
        spots[14].add_info({types[2],types[13],types[3]}, {nums[2],nums[13],nums[3]}, {10,11,20}, 15);
        spots[15].add_info({types[3]}, {nums[3]}, {11,21}, 16);
        
        spots[16].add_info({types[10],types[11]}, {nums[10],nums[11]}, {12,22,23}, 17);
        spots[17].add_info({types[11],types[12],types[17]}, {nums[11],nums[12],nums[17]}, {23,23,13}, 18);
        spots[18].add_info({types[12],types[13],"Desert"}, {nums[12],nums[13],nums[18]}, {23,25,14}, 19);
        spots[19].add_info({types[3],types[13],types[14]}, {nums[3],nums[13],nums[14]}, {25,26,15}, 20);
        spots[20].add_info({types[3],types[4]}, {nums[3],nums[4]}, {26,27,16}, 21);
        
        spots[21].add_info({types[10]}, {nums[10]}, {17,28}, 22);
        spots[22].add_info({types[10],types[11],types[17]}, {nums[10],nums[11],nums[17]}, {17,18,29}, 23);
        spots[23].add_info({types[12],types[17],"Desert"}, {nums[12],nums[17],nums[18]}, {18,19,30}, 24);
        spots[24].add_info({types[13],types[14],"Desert"}, {nums[13],nums[14],nums[18]}, {19,20,31}, 25);
        spots[25].add_info({types[3],types[14],types[4]}, {nums[3],nums[14],nums[4]}, {20,21,32}, 26);
        spots[26].add_info({types[4]}, {nums[4]}, {21,33}, 27);
        
        spots[27].add_info({types[10]}, {nums[10]}, {34,22}, 28);
        spots[28].add_info({types[9],types[10],types[17]}, {nums[9],nums[10],nums[17]}, {34,35,23}, 29);
        spots[29].add_info({types[16],types[17],"Desert"}, {nums[16],nums[17],nums[18]}, {35,36,23}, 30);
        spots[30].add_info({types[14],types[15],"Desert"}, {nums[14],nums[15],nums[18]}, {36,37,25}, 31);
        spots[31].add_info({types[4],types[5],types[14]}, {nums[4],nums[5],nums[14]}, {37,38,26}, 32);
        spots[32].add_info({types[4]}, {nums[4]}, {38,27}, 33);
        
        spots[33].add_info({types[9],types[10]}, {nums[9],nums[10]}, {28,39,29}, 34);
        spots[34].add_info({types[9],types[16],types[17]}, {nums[9],nums[16],nums[17]}, {29,30,40}, 35);
        spots[35].add_info({types[15],types[16],"Desert"}, {nums[15],nums[16],nums[18]}, {30,31,41}, 36);
        spots[36].add_info({types[5],types[14],types[15]}, {nums[5],nums[14],nums[15]}, {31,32,42}, 37);
        spots[37].add_info({types[4],types[5]}, {nums[4],nums[5]}, {32,33,43}, 38);
        
        spots[38].add_info({types[9]}, {nums[9]}, {44,34}, 39);
        spots[39].add_info({types[8],types[9],types[16]}, {nums[8],nums[9],nums[16]}, {44,45,35}, 40);
        spots[40].add_info({types[7],types[15],types[16]}, {nums[7],nums[15],nums[16]}, {45,46,36}, 41);
        spots[41].add_info({types[5],types[6],types[15]}, {nums[5],nums[6],nums[15]}, {46,47,37}, 42);
        spots[42].add_info({types[5]}, {nums[5]}, {47,38}, 43);

        spots[43].add_info({types[8],types[9]}, {nums[8],nums[9]}, {48,39,40}, 44);
        spots[44].add_info({types[7],types[8],types[16]}, {nums[7],nums[8],nums[16]}, {40,41,49}, 45);
        spots[45].add_info({types[6],types[7],types[15]}, {nums[6],nums[7],nums[15]}, {41,42,50}, 46);
        spots[46].add_info({types[5],types[6]}, {nums[5],nums[6]}, {42,43,51}, 47);

        spots[47].add_info({types[8]}, {nums[8]}, {52,44}, 48);
        spots[48].add_info({types[7],types[8]}, {nums[7],nums[8]}, {52,53,45}, 49);
        spots[49].add_info({types[6],types[7]}, {nums[6],nums[7]}, {53,54,46}, 50);
        spots[50].add_info({types[6]}, {nums[6]}, {54,47}, 51);

        spots[51].add_info({types[8]}, {nums[8]}, {48,49}, 52);
        spots[52].add_info({types[7]}, {nums[7]}, {49,50}, 53);
        spots[53].add_info({types[6]}, {nums[6]}, {50,51}, 54);
    }
    Board::~Board(){}

    void Board::printBoard(){
        cout << "            " << spots[0] << spots[1] << spots[2] << endl;
        cout << "           /   \\   /   \\   /   \\" << endl;
        cout << "        " << spots[3] << spots[4] << spots[5] << spots[6] << endl;
        cout << "         |"<<spots[0].getType(0)<<"|"<<spots[1].getType(0)<<"|"<<spots[2].getType(0)<<"|" << endl;
        cout << "        " << spots[7] << spots[8] << spots[9] << spots[10] << endl;
        cout << "       /    \\  /    \\  /    \\  /    \\" << endl;
        cout << "    " << spots[11] << spots[12] << spots[13] << spots[14] << spots[15] << endl;
        cout << "     |"<<spots[7].getType(0)<<"|"<<spots[8].getType(0)<<"|"<<spots[9].getType(0)<<"|"<<spots[10].getType(0)<<"|" << endl;
        cout << "    " << spots[16] << spots[17] << spots[18] << spots[19] << spots[20] << endl;
        cout << "   /    \\  /    \\  /    \\  /    \\  /    \\" << endl;
        cout << spots[21] << spots[22] << spots[23] << spots[24] << spots[25] << spots[26] << endl;
        cout << " |"<<spots[16].getType(0)<<"|"<<spots[17].getType(0)<<"|"<<spots[18].getType(0)<<"|"<<spots[19].getType(0)<<"|"<<spots[20].getType(0)<<"|" << endl;
        cout << spots[27] << spots[28] << spots[29] << spots[30] << spots[31] << spots[32] << endl;
        cout << "   \\    /  \\    /  \\    /  \\    /  \\    /" << endl;
        cout << "    " << spots[33] << spots[34] << spots[35] << spots[36] << spots[37] << endl;
        cout << "     |"<<spots[43].getType(0)<<"|"<<spots[44].getType(0)<<"|"<<spots[45].getType(0)<<"|"<<spots[10].getType(0)<<"|" << endl;
        cout << "    " << spots[38] << spots[39] << spots[40] << spots[41] << spots[42] << endl;
        cout << "       \\    /  \\    /  \\    /  \\    /" << endl;
        cout << "        " << spots[43] << spots[44] << spots[45] << spots[46] << endl;
        cout << "         |"<<spots[51].getType(0)<<"|"<<spots[52].getType(0)<<"|"<<spots[53].getType(0)<<"|" << endl;
        cout << "        " << spots[47] << spots[48] << spots[49] << spots[50] << endl;
        cout << "           \\    /  \\    /  \\    /" << endl;
        cout << "            " << spots[51] << spots[52] << spots[53] << "\n\n-----------------------------------\n\n";
    }

}