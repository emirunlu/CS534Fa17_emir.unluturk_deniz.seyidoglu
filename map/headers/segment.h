#ifndef Segment_H
#define Segment_H
#include <vector>
#include "./cell.h"

class Segment {
public:
	Segment();
	~Segment();
	void print();
protected:
private:
	std::vector<Cell*> cells;
};

#endif