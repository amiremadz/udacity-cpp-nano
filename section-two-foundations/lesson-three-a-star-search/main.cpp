//
// Created by Michael Harris on 04/18/2020
//

#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::sort;
using std::vector;
using std::cout;
using std::string;
using std::istringstream;
using std::ifstream;

enum class State {
    k_empty,
    k_obstacle,
    k_closed,
    k_path,
    k_start,
    k_stop
};

const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<State> ParseLine(string line){
    istringstream string_line(line);
    int n;
    char c;
    vector<State> row;
    while(string_line >> n >> c){
        if(n==0){
            row.push_back(State::k_empty);
        } else {
            row.push_back(State::k_obstacle);
        }
    }
    return row;
}

vector<vector<State>> ReadFile(string path){
    ifstream file(path);
    vector<vector<State>> grid{};
    if (file) {
        string line;
        while(getline(file, line)){
            vector<State> row = ParseLine(line);
            grid.push_back(row);
        }
    } else {
        cout << "Stream not created successfully" << "\n";
    }
    return grid;
}

//
bool Compare(vector<int> arg1, vector<int> arg2){
    int f_arg1 = arg1[2] + arg1[3];
    int f_arg2 = arg2[2] + arg2[3];

    // return a boolean of true if the first arg is greater than second arg
    return f_arg1 > f_arg2;
}

// sorts the cells in the 2D vector by the values returned in the Compare function
void CellSort(vector<vector<int>> *v) {
    sort(v->begin(), v->end(), Compare);
}

// A* heuristic
// Manhattan Distance function --> |x2 - x1| + |y2 - y1|
int Heuristic(int currentCell[2], int goal[2]) {
    return abs(goal[0] - currentCell[0]) + abs(goal[1] - currentCell[1]);
}

// Check valid cell
bool CheckValidCell(int x, int y, vector<vector<State>> &grid){
    bool on_grid_x = (x >= 0 && x < grid.size());
    bool on_grid_y = (y >= 0 && y < grid[0].size());
    if (on_grid_x && on_grid_y){
        return grid[x][y] == State::k_empty;
    }
    return false;
}

void AddToOpen(int x, int y, int g, int h,
               vector<vector<int>> &open, vector<vector<State>> &grid){
    // add values to open vector and mark the cell passed in as closed
    open.push_back(vector<int> {x, y, g, h});
    grid[x][y] = State::k_closed;
}

//
void ExpandNeighbors(vector<int> &current, vector<vector<int>> &open,
                     vector<vector<State>> &grid, int (&goal)[2]){
    int x = current[0];
    int y = current[1];
    int g = current[2];

    for (auto i : delta){
        int x2 = x + i[0];
        int y2 = y + i[1];

        //
        if (CheckValidCell(x2, y2, grid)){
            int g2 = g + 1;
            int tempCurrent[2] = {x2, y2};
            int h2 = Heuristic(tempCurrent ,goal);
            AddToOpen(x2, y2, g2, h2, open, grid);
        }
    }
}

// A* search algorithm
vector<vector<State>> Search(vector<vector<State>> grid) {
    cout << "\nReading grid of size " << grid.size() << "x" << grid[0].size() << "...\n";
    cout << "Start: (0, 0)\n" << "Goal: (" << grid.size() - 1 << ", " << grid[0].size() - 1 << ")\n\n";

    // open vector initialization
    vector<vector<int>> open{};

    // coordinates for current cell and goal
    int init[2] = {0, 0};
    int goal[2] = {int(grid.size() - 1), int(grid[0].size() - 1)};

    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(init, goal);

    // add the values to the open vector initialized above
    AddToOpen(x, y, g, h, open, grid);

    // try !open.empty() next
    while (open.size() > 0){
        CellSort(&open);
        auto current = open.back();
        open.pop_back();
        x = current[0];
        y = current[1];
        grid[x][y] = State::k_path;
        if (x == goal[0] && y == goal[1]){
            grid[0][0] = State::k_start;
            grid[int(grid.size() - 1)][int(grid[0].size() - 1)] = State::k_stop;
            return grid;
        }
        ExpandNeighbors(current, open, grid, goal);
    }

    // We've run out of new nodes to explore and haven't found a path.
    cout << "No path found. See failed try below:\n" << "\n";
    return grid;
}

string CellString(State cell){
    switch (cell) {
        case State::k_obstacle:
            return "⛰ ";
        case State::k_path:
            return "🚗 ";
        case State::k_start:
            return "🚦 ";
        case State::k_stop:
            return "🏁 ";
        default:
            return "  ";
    }
}

void PrintGrid(vector<vector<State>> grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            cout << CellString(grid[i][j]) << ",";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<State>> grid = ReadFile("/Users/michaelharris/udacity-cpp-nano/section-two-foundations/lesson-three-a-star-search/grids/grid.csv");
    PrintGrid(grid);
    vector<vector<State>> solution = Search(grid);
    PrintGrid(solution);
}