#ifndef FILEREADER_H
#define FILEREADER_H
#include "Cell.h"
#include <string>
#include <vector>

using namespace std;

class FileReader {
    public:
        FileReader(string file, vector <vector <Cell*>> &grid);
};

#endif