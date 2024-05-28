// ID: 322453689
// MAIL: adam.sinale@gmail.com

#include "board.hpp"

#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine
#include <chrono> 

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
        vector<int> nums = {5,2,6,3,8,10,9,12,11,4,8,10,9,4,5,6,3,11,9,7};
        vector<string> types = {"Forest","Forest","Forest","Forest",
                                "Agricultural Land","Agricultural Land","Agricultural Land","Agricultural Land",
                                "Hills","Hills","Hills","Hills",
                                "Mountains","Mountains","Mountains",
                                "Pasture Land","Pasture Land","Pasture Land"};
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(types.begin(), types.end(), std::default_random_engine(seed));

        spots[0].add_info({types[0]}, {nums[0]}, {spots[3],spots[4]});
        spots[1].add_info({types[1]}, {nums[1]}, {spots[4],spots[5]});
        spots[2].add_info({types[2]}, {nums[2]}, {spots[5],spots[6]});

        spots[3].add_info({types[0]}, {nums[0]}, {spots[0],spots[7]});
        spots[4].add_info({types[0],types[1]}, {nums[0],nums[1]}, {spots[0],spots[1],spots[8]});
        spots[5].add_info({types[1],types[2]}, {nums[1],nums[2]}, {spots[1],spots[2],spots[9]});
        spots[6].add_info({types[2]}, {nums[2]}, {spots[2],spots[10]});

        spots[7].add_info({types[0],types[11]}, {nums[0],nums[11]}, {spots[3],spots[11],spots[12]});
        spots[8].add_info({types[0],types[1],types[12]}, {nums[0],nums[1],nums[12]}, {spots[12],spots[13],spots[4]});
        spots[9].add_info({types[1],types[2],types[13]}, {nums[1],nums[2],nums[13]}, {spots[13],spots[14],spots[5]});
        spots[10].add_info({types[2],types[3]}, {nums[2],nums[3]}, {spots[14],spots[15],spots[6]});
        
        spots[11].add_info({types[11]}, {nums[11]}, {spots[7],spots[16]});
        spots[12].add_info({types[0],types[11],types[12]}, {nums[0],nums[11],nums[12]}, {spots[7],spots[8],spots[17]});
        spots[13].add_info({types[1],types[12],types[13]}, {nums[1],nums[12],nums[13]}, {spots[8],spots[9],spots[18]});
        spots[14].add_info({types[2],types[13],types[3]}, {nums[2],nums[13],nums[3]}, {spots[9],spots[10],spots[19]});
        spots[15].add_info({types[3]}, {nums[3]}, {spots[10],spots[20]});
        
        spots[16].add_info({types[10],types[11]}, {nums[10],nums[11]}, {spots[11],spots[21],spots[22]});
        spots[17].add_info({types[11],types[12],types[17]}, {nums[11],nums[12],nums[17]}, {spots[22],spots[23],spots[12]});
        spots[18].add_info({types[12],types[13],types[18]}, {nums[12],nums[13],nums[18]}, {spots[23],spots[24],spots[13]});
        spots[19].add_info({types[3],types[13],types[14]}, {nums[3],nums[13],nums[14]}, {spots[24],spots[25],spots[14]});
        spots[20].add_info({types[3],types[4]}, {nums[3],nums[4]}, {spots[25],spots[26],spots[15]});
        
        spots[21].add_info({types[10]}, {nums[10]}, {spots[16],spots[27]});
        spots[22].add_info({types[10],types[11],types[17]}, {nums[10],nums[11],nums[17]}, {spots[16],spots[17],spots[28]});
        spots[23].add_info({types[12],types[17],types[18]}, {nums[12],nums[17],nums[18]}, {spots[17],spots[18],spots[29]});
        spots[24].add_info({types[13],types[14],types[18]}, {nums[13],nums[14],nums[18]}, {spots[18],spots[19],spots[30]});
        spots[25].add_info({types[3],types[14],types[4]}, {nums[3],nums[14],nums[4]}, {spots[19],spots[20],spots[31]});
        spots[26].add_info({types[4]}, {nums[4]}, {spots[20],spots[32]});
        
        spots[27].add_info({types[10]}, {nums[10]}, {spots[33],spots[21]});
        spots[28].add_info({types[9],types[10],types[17]}, {nums[9],nums[10],nums[17]}, {spots[33],spots[34],spots[22]});
        spots[29].add_info({types[16],types[17],types[18]}, {nums[16],nums[17],nums[18]}, {spots[34],spots[35],spots[23]});
        spots[30].add_info({types[14],types[15],types[18]}, {nums[14],nums[15],nums[18]}, {spots[35],spots[36],spots[24]});
        spots[31].add_info({types[4],types[5],types[14]}, {nums[4],nums[5],nums[14]}, {spots[36],spots[37],spots[25]});
        spots[32].add_info({types[4]}, {nums[4]}, {spots[37],spots[26]});
        
        spots[33].add_info({types[9],types[10]}, {nums[9],nums[10]}, {spots[27],spots[38],spots[28]});
        spots[34].add_info({types[9],types[16],types[17]}, {nums[9],nums[16],nums[17]}, {spots[28],spots[29],spots[39]});
        spots[35].add_info({types[15],types[16],types[18]}, {nums[15],nums[16],nums[18]}, {spots[29],spots[30],spots[40]});
        spots[36].add_info({types[5],types[14],types[15]}, {nums[5],nums[14],nums[15]}, {spots[30],spots[31],spots[41]});
        spots[37].add_info({types[4],types[5]}, {nums[4],nums[5]}, {spots[31],spots[32],spots[42]});
        
        spots[38].add_info({types[9]}, {nums[9]}, {spots[43],spots[33]});
        spots[39].add_info({types[8],types[9],types[16]}, {nums[8],nums[9],nums[16]}, {spots[43],spots[44],spots[34]});
        spots[40].add_info({types[7],types[15],types[16]}, {nums[7],nums[15],nums[16]}, {spots[44],spots[45],spots[35]});
        spots[41].add_info({types[5],types[6],types[15]}, {nums[5],nums[6],nums[15]}, {spots[45],spots[46],spots[36]});
        spots[42].add_info({types[5]}, {nums[5]}, {spots[46],spots[37]});

        spots[43].add_info({types[8],types[9]}, {nums[8],nums[9]}, {spots[47],spots[38],spots[39]});
        spots[44].add_info({types[7],types[8],types[16]}, {nums[7],nums[8],nums[16]}, {spots[39],spots[40],spots[48]});
        spots[45].add_info({types[6],types[7],types[15]}, {nums[6],nums[7],nums[15]}, {spots[40],spots[41],spots[49]});
        spots[46].add_info({types[5],types[6]}, {nums[5],nums[6]}, {spots[41],spots[42],spots[50]});

        spots[47].add_info({types[8]}, {nums[8]}, {spots[51],spots[43]});
        spots[48].add_info({types[7],types[8]}, {nums[7],nums[8]}, {spots[51],spots[52],spots[44]});
        spots[49].add_info({types[6],types[7]}, {nums[6],nums[7]}, {spots[52],spots[53],spots[45]});
        spots[50].add_info({types[6]}, {nums[6]}, {spots[53],spots[46]});

        spots[51].add_info({types[8]}, {nums[8]}, {spots[47],spots[48]});
        spots[52].add_info({types[7]}, {nums[7]}, {spots[48],spots[49]});
        spots[53].add_info({types[6]}, {nums[6]}, {spots[49],spots[50]});
    }
    Board::~Board(){}

    void Board::printBoard(){
        cout << "   " << endl;
        cout << "   " << endl;
        
        cout << "x     " << spots[21] << "     ";
    }

}