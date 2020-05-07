#include "Cell.h"
#include <set>
#include <vector>

Cell::Cell(int x, int y, int value) {
		this->x = x;
		this->y = y;
		this->value = value;
}

bool Cell::is_writable() {
	return false;
}