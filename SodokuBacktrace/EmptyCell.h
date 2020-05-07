#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "Cell.h"
#include <set>
#include <vector>

const int GRID_DIMENSION = 9;
const int SQUARE_DIMENSION = 3;

class EmptyCell: public Cell {
public:
	std::set <int> candidates;

	EmptyCell(int x, int y);

	void RemoveCandidates(std::vector <std::vector <Cell*>>& grid);

	void RemoveValue();

	bool SetValueAsNextCandidate();

	virtual bool is_writable();

private:


	void checkRow(std::vector <std::vector <Cell*>> &grid, std::set<int> &minus);

	void checkCol(std::vector <std::vector <Cell*>> &grid, std::set<int> &minus);

	void checkSquare(std::vector <std::vector <Cell*>> &grid, std::set<int> &minus);
};

#endif
