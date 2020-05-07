#include "FileReader.h"
#include "EmptyCell.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const int DIMENSION = 9;

FileReader::FileReader(std::string file, std::vector<std::vector <Cell*>> &grid) {
    int cnt, x, y;
    string output;
    ifstream fileObj;
    
    cnt = 0;
    fileObj.open(file);

    if (fileObj.is_open()) {
        while (!fileObj.eof()) {
            x = cnt % DIMENSION;
            y = cnt / DIMENSION;
            fileObj >> output;
            if (output == ".") {
                grid [y][x] = new EmptyCell(x, y);
                ++cnt;
            }
            else if (std::isdigit(output.at(0))) {
                grid[y][x] = new Cell(x, y, stoi(output));
                ++cnt;
            } 
        }
    }
    else {
        std::cout << "Couldn't open file";
    }

    fileObj.close();
};
