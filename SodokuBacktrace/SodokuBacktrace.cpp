
#include "FileReader.h"
#include <iostream>
#include <vector>

using namespace std;

const string INPUT_FILE = "Input.txt";
const int DIMENSION = 9;

int main() {

    vector <vector <int>> grid;
    grid.resize(DIMENSION);
    for (int i = 0; i < DIMENSION; ++i) {
        grid[i].resize(DIMENSION);
    }

    FileReader fr = FileReader(INPUT_FILE, grid);
    
    cout << "Hello World!\n";
}
