//
// Created by Michael Harris on 4/12/20.
//

#include <iostream>
#include <vector>
using std::vector;

int main() {
    // create a 2D vector named board
    vector<vector<int>> board {
            {0,1,0,0,0,0},
            {0,1,0,0,0,0},
            {0,1,0,0,0,0},
            {0,1,0,0,0,0},
            {0,0,0,0,1,0}
    };

    std::cout << "Board vector created" << std::endl;
    return 0;
}