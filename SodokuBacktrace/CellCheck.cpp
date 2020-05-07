#include "CellCheck.h"
#include <vector>

const int GRID_DIMENSION = 9; 
const int SQUARE_DIMENSION = 3;

bool checkRow(std::vector <std::vector <int>> &grid, int candidate, int x, int y) {

	for (int i = 0; i < GRID_DIMENSION; ++i) {
		if (grid[y][i] == candidate) {
			return false;
		}
	}
	return true;
}

bool checkCol(std::vector <std::vector <int>>& grid, int candidate, int x, int y) {

	for (int j = 0; j < GRID_DIMENSION; ++j) {
		if (grid[j][x] == candidate) {
			return false;
		}
	}
	return true;
}

bool checkSquare(std::vector <std::vector <int>>& grid, int candidate, int x, int y) {
	
	int xSquare, ySquare;
	xSquare = x / 3;
	ySquare = y / 3;

	for (int i = 0; i < SQUARE_DIMENSION; ++i) {
		for (int j = 0; j < SQUARE_DIMENSION; ++j) {
			if (grid[ySquare * SQUARE_DIMENSION + j][xSquare * SQUARE_DIMENSION + i] == candidate) {
				return false;
			}
		}
	}
	return true;
}