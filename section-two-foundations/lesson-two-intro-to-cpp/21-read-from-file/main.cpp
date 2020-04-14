//
// Created by Michael Harris on 4/13/20.
//

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream file("/Users/michaelharris/udacity-cpp-nano/section-two-foundations/lesson-two-intro-to-cpp/21-read-from-file/board.csv");
    if (file) {
        string line;
        while(getline(file, line)) {
            cout << line << "\n";
        }
    } else {
        cout << "Stream was not created successfully" << endl;
    }
}