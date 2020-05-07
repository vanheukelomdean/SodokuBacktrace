#include "EmptyCell.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

EmptyCell::EmptyCell(int x, int y): Cell(x, y, NULL) {
	this->candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
}



void EmptyCell::RemoveCandidates(std::vector <std::vector <Cell*>>& grid) {
	std::set<int> minus;
	std::set<int> result;

	if (this->value == NULL) {
		this->candidates = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	}

	this->checkRow(grid, minus);

	this->checkCol(grid, minus);

	this->checkSquare(grid, minus);

	std::set_difference(this->candidates.begin(), this->candidates.end(), minus.begin(), minus.end(), 
			std::inserter(result, result.end()));

	this->candidates = result;
}
void EmptyCell::RemoveValue() {
	this->candidates.erase(this->value);
	this->value = NULL;
}

bool EmptyCell::SetValueAsNextCandidate() {
	std::cout << "Options: ";
	for (auto it = this->candidates.begin(); it != this->candidates.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\n";

	if (this->candidates.empty()) {
		return false;
	}
	else {
		this->value = *this->candidates.begin();
		
		std::cout << "Set " << this->value << "\n";
	}
	return true;
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

bool EmptyCell::is_writable() {
	return true;
}