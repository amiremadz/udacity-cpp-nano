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

enum class State {
    k_empty,
    k_obstacle
};

vector<State> parseLine(string line){
    istringstream string_line(line);
    int n;
    char c;
    vector<State> d_vector;
    while(string_line >> n >> c && c == ','){
        if(n==0){
            d_vector.push_back(State::k_empty);
        } else {
            d_vector.push_back(State::k_obstacle);
        }
    }
    return d_vector;
}

vector<vector<State>> readFile(string path){
    ifstream file(path);
    vector<vector<State>> dd_vector{};
    if (file) {
        string line;
        while(getline(file, line)){
            vector<State> d_vector = parseLine(line);
            dd_vector.push_back(d_vector);
        }
    } else {
        cout << "Stream not created successfully" << "\n";
    }
    return dd_vector;
}

string cellString(State cell){
    switch (cell) {
        case State::k_obstacle:
            return "⛰ ";
        case State::k_empty:
            return "0 ";
    }
}


void printFile(const vector<vector<State>> dd_vector){
    for(vector<State> d_vector: dd_vector){
        for(State col: d_vector){
            cout << cellString(col) << ",";
        }
        cout << "\n";
    }
}

int main() {
    printFile(readFile("board.csv"));
    return 0;
}

