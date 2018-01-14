#ifndef Map_H
#define Map_H
#include <vector>
#include "../../map/headers/segment.h"
#include "../../map/headers/nullCell.h"

class Map {
public:
	Map();
	~Map();
	void print();
	Cell* searchOccupied(int currentIndex);
	Cell* searchSymbol(Symbol* symbol, int currentIndex);
	Cell* getFirstCell();
protected:
private:
	std::vector<Segment*> segments;
};

#endif