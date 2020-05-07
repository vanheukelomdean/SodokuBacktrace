#ifndef CELLCHECK_H
#define CELLCHECK_H
#include <set>
#include <vector>



const int GRID_DIMENSION = 9;
const int SQUARE_DIMENSION = 3;

std::set <int> checkRow(std::vector <std::vector <int>> &grid, std::set <int> &candidates, int y);

std::set <int> checkCol(std::vector <std::vector <int>> &grid, std::set <int> &candidates, int x);

std::set <int> checkSquare(std::vector <std::vector <int>> &grid, std::set <int> &candidates, int x, int y);

#endif
