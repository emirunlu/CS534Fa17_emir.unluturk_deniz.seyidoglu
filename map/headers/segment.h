#ifndef Segment_H
#define Segment_H
#include <vector>
#include "./nullCell.h"
#include "./cell.h"
#include "./boat.h"

class Segment {
public:
	Segment(bool lastSegment);
	~Segment();
	void print();
	Cell* searchOccupied(int currentIndex);
	Cell* searchSymbol(Symbol* symbol, int currentIndex);
	std::vector<Cell*> getCells();
	Cell* getFirstCell();
protected:
private:
	std::vector<Cell*> cells;
};

#endif