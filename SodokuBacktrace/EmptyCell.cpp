#include "EmptyCell.h"
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

EmptyCell::EmptyCell(int x, int y): Cell(x, y, NULL) {
	this->candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
}

void EmptyCell::RemoveCandidates(std::vector <std::vector <Cell*>> &grid) {
	std::set<int> minus;

	this->checkRow(grid, minus);
	this->checkCol(grid, minus);

	std::set_difference(candidates.begin(), candidates.end(), minus.begin(), minus.end(),
		std::inserter(candidates, candidates.end()));
}

int EmptyCell::GetNextCandidate() {
	return *candidates.begin();
}

void EmptyCell::checkRow(std::vector <std::vector <Cell*>>& grid, std::set<int> &minus) {

	for (int i = 0; i < GRID_DIMENSION; ++i) {
		minus.insert(grid[this->y][i]->value);
	}
}

void EmptyCell::checkCol(std::vector <std::vector <Cell*>>& grid, std::set<int> &minus) {

	for (int i = 0; i < GRID_DIMENSION; ++i) {
		minus.insert(grid[i][this->x]->value);
	}
}

void  EmptyCell::checkSquare(std::vector <std::vector <Cell*>>& grid, std::set<int>& minus) {
	int xSquare, ySquare;

	xSquare = (this->x / SQUARE_DIMENSION) * SQUARE_DIMENSION;
	ySquare = (this->y / SQUARE_DIMENSION) * SQUARE_DIMENSION;

	for (int i = xSquare; i < xSquare + SQUARE_DIMENSION; ++i) {
		for (int j = ySquare; j < ySquare + SQUARE_DIMENSION; ++j) {
			minus.insert(grid[j][i]->value);
		}
	}
}