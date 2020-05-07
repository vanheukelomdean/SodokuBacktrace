#include "FileReader.h"
#include "CellCheck.h"
#include <iostream>
#include <vector>

using namespace std;

const int DIMENSION = 9;
const string INPUT_FILE = "Input.txt";

int main() {

    vector <vector <Cell*>> grid;

    //init sodoku grid from file
    grid.resize(DIMENSION);
    for (int i = 0; i < DIMENSION; ++i) {
        grid[i].resize(DIMENSION);
    }


    FileReader(INPUT_FILE, grid);

    /*
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    cout << k * 3 + l << " " << i * 3 + j << ", ";
                    cout << (*(grid[i* 3 + j][k * 3 + l])->value == NULL? "." : to_string(*(grid[i * 3 + j][k * 3 + l])->value)) << " ";
                }
            }
        }
    }
    */
}
