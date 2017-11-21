#ifndef Map_H
#define Map_H
#include <vector>
#include "../../map/headers/segment.h"

class Map {
public:
	Map();
	~Map();
	void printSegments();
protected:
private:
	std::vector<Segment*> segments;
};

#endif