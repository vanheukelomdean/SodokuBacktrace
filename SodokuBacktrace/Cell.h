#ifndef CELL_H
#define CELL_H
#include <set>
#include <vector>

class Cell {
public:
	int value;
	int x;
	int y;
	Cell(int x, int y, int value);

	bool is_writable();

protected:


};

#endif
