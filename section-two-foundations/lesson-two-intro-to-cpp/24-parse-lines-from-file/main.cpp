//
// Created by Michael Harris on 4/15/20.
//
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::vector;
using std::cout;
using std::string;
using std::istringstream;
using std::ifstream;

/*
 * Parses each line from a given string
 */
vector<int> parseLine(string line){
    istringstream string_line(line);
    int n;
    char c;
    // this vector will be a 1D vector in the 2D vector for each line parsed
    vector<int> d_vector;

    // while not at the end of the line append to the d_vector
    while(string_line >> n >> c){
        d_vector.push_back(n);
    }

    // needs to return the 1D vector so we can append the 1D vector to the 2D vector
    return d_vector;
}

vector<vector<int>> readFile(string path){
    // input file stream from the file provided by the path
    ifstream file(path);

    // the 2D vector
    vector<vector<int>> dd_vector{};

    // if file stream connected then parse line from file
    // append file to 1D vector and then append 1D vector to
    // 2D vector
    if (file) {
        string line;
        while(getline(file, line)){
            vector<int> d_vector = parseLine(line);
            dd_vector.push_back(d_vector);
        }
    } else {
        // error message
        cout << "Stream not created successfully" << "\n";
    }
    // returns the 2D vector object
    return dd_vector;
}


void printFile(const vector<vector<int>> dd_vector){
    // prints the 2D vector passed by iterating over each row
    // and then each column in the row
    for(vector<int> d_vector: dd_vector){
        for(int col: d_vector){
            cout << col << ",";
        }
        cout << "\n";
    }
}

int main() {
    // only works with .csv files
    printFile(readFile("/Users/michaelharris/udacity-cpp-nano/section-two-foundations/lesson-two-intro-to-cpp/24-parse-lines-from-file/board.csv"));
}

