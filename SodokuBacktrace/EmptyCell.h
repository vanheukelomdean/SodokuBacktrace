#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "Cell.h"
#include <set>
#include <vector>

const int GRID_DIMENSION = 9;
const int SQUARE_DIMENSION = 3;

class EmptyCell: public Cell {
public:
	EmptyCell(int x, int y);

	virtual void RemoveCandidates();

	void RemoveCandidates(std::vector <std::vector <Cell*>>& grid);

	int GetNextCandidate();

	virtual bool is_writable();

private:
	std::set <int> candidates;

	void checkRow(std::vector <std::vector <Cell*>> &grid, std::set<int> &minus);

	void checkCol(std::vector <std::vector <Cell*>> &grid, std::set<int> &minus);

	void checkSquare(std::vector <std::vector <Cell*>> &grid, std::set<int> &minus);
};

#endif
