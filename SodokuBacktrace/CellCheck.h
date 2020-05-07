#ifndef CELLCHECK_H
#define CELLCHECK_H
#include <vector>

const int GRID_DIMENSION = 9;
const int SQUARE_DIMENSION = 3;

bool checkRow(std::vector <std::vector <int>>& grid, int candidate, int x, int y);

bool checkCol(std::vector <std::vector <int>>& grid, int candidate, int x, int y);

bool checkSquare(std::vector <std::vector <int>>& grid, int candidate, int x, int y);

#endif
