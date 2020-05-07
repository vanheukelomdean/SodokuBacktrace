#include "FileReader.h"
#include <iostream>
#include <vector>

using namespace std;

const int DIMENSION = 9;
const string INPUT_FILE = "Input.txt";

void printToConsole(vector <vector <Cell*>>& grid) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " ";
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    cout << (grid[i * 3 + j][k * 3 + l]->value == NULL ? "." : to_string(grid[i * 3 + j][k * 3 + l]->value)) << " ";
                }
                cout << (k != 2 ? "| " : "");
            }
            cout << "\n";
        }
        cout << (i != 2 ? "-------|-------|-------\n" : "");
    }
    cout << "\n";
}

bool depthFirstSearch(vector <vector <Cell*>>& grid, vector <EmptyCell*> &solution, int depth = 0) {
    bool assigned, complete;
    solution[depth]->RemoveCandidates(grid);
    assigned = true;
    while (assigned) {
        cout << "depth                                         - " << depth << "\n";
        assigned = solution[depth]->SetValueAsNextCandidate();
        printToConsole(grid);
        if (assigned) {
            if (depth == solution.size() - 1) { 
                return true;
            }
            else {
                complete = depthFirstSearch(grid, solution,  depth + 1);
                if (complete) {
                    return true;
                }
            }
        }
        else {
            if (depth == 0) {
                return false;
            }
            else {
                cout << "Remove (" << solution[depth]->x << ", " << solution[depth]->y << ")   -   " << solution[depth]->value << "\n";
                solution[depth - 1]->RemoveValue();
                return false;
            }

        }
    }
}


int main() {
    vector <vector <Cell*>> grid;
    vector <EmptyCell*> solution;
    cout << "hello";
    //init sodoku grid from file
    grid.resize(DIMENSION);
    for (int i = 0; i < DIMENSION; ++i) {
        grid[i].resize(DIMENSION);
    }
    FileReader(INPUT_FILE, grid, solution);

    cout << solution.size() << " numbers to place \n\n";

    printToConsole(grid);

    bool complete = false;
    //begin depth first search
    cout << depthFirstSearch(grid, solution);
}




