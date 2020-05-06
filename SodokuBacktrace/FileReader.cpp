#include "FileReader.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


FileReader::FileReader(std::string file, std::vector <std::vector <int>> &grid) {
    int x;
    string output;
    ifstream fileObj;
    
    x = 0;
    fileObj.open(file);

    if (fileObj.is_open()) {
        while (!fileObj.eof()) {
            fileObj >> output;
            if (output == ".") {
                grid[0].push_back(0);
                ++x;
            }
            else if (std::isdigit(output.at(0))) {
                grid[0].push_back(stoi(output));
                ++x;
            } 
        }
    }
    else {
        std::cout << "Couldn't open file";
    }

    fileObj.close();
};
