#ifndef Segment_H
#define Segment_H
#include <vector>
#include "./cell.h"
#include "./boat.h"

class Segment {
public:
	Segment(bool lastSegment);
	~Segment();
	void print();
	Cell* searchSymbol(Symbol* symbol);
	Cell* getFirstCell();
protected:
private:
	std::vector<Cell*> cells;
};

#endif