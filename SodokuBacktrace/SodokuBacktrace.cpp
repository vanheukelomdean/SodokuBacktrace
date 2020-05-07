#include "FileReader.h"
#include <iostream>
#include <vector>

using namespace std;

const int DIMENSION = 9;
const string INPUT_FILE = "Input.txt";

int main() {
    bool search;
    int cnt;
    vector <vector <Cell*>> grid;
    vector <EmptyCell*> solution;

    //init sodoku grid from file
    grid.resize(DIMENSION);
    for (int i = 0; i < DIMENSION; ++i) {
        grid[i].resize(DIMENSION);
    }
    FileReader(INPUT_FILE, grid, solution);

    //begin depth first search
    search= true;
    cnt = 0;
    while (search) {
        solution[cnt]->RemoveCandidates(grid);

        break;
    }
}

void printToConsole(vector <vector <Cell*>> &grid) {
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
}

