//
// Created by Michael Harris on 4/13/20.
//

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void PrintBoard(vector< vector<int> > board) {
    // for row in matrix
    for (vector<int> i: board) {
        //for column in row
        for (int n: i) {
            cout << n;
        }
        cout << std::endl;
    }
}

int main() {
    vector< vector<int> > board {{0,1,0,0,0,0},
                                 {0,1,0,0,0,0},
                                 {0,1,0,0,0,0},
                                 {0,1,0,0,0,0},
                                 {0,0,0,0,1,0}};

    PrintBoard(board);
}