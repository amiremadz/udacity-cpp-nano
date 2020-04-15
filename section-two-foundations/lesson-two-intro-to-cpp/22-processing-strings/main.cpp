//
// Created by Michael Harris on 4/15/20.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string str("1,2,3,");

    istringstream my_stream(str);

    // to handle the commas in the string stream
    char c;

    //to handle the numbers in the string stream
    int n;

    while (my_stream >> n >> c) {
        // do not use std::endl unless flushing the stream is required
        // otherwise using std::endl will hurt performance
        cout << n << c << "\n";
    }
    cout << "Stream has stopped" << endl;
}