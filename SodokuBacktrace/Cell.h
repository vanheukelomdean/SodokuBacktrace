#ifndef CELL_H
#define CELL_H
#include <set>
#include <vector>

class Cell {
public:
	int value;

	Cell(int x, int y, int value);

	bool is_writable();

protected:
	int x;
	int y;

};

#endif
