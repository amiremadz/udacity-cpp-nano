/*
 * Created by Michael Harris on 4/15/20.
 * @dev: Uses the stream of a string to take in numbers and append
 *       those numbers to a vector.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str("1,2,3,");
    vector<int> vec{-1, 0};

    istringstream my_stream(str);

    char c;
    int n;

    while (my_stream >> n >> c) {
        vec.push_back(n);
    }
    cout << "Stream has stopped" << endl;

    for(int i: vec) {
        cout << i << "\n";
    }
}