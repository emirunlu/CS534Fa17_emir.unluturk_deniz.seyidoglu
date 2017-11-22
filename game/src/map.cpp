#include <iostream>
#include "../headers/map.h"
#include "../../map/headers/segment.h"

using namespace std;

Map::Map() {
	for (int i = 0; i < 5; ++i) {
		segments.push_back(new Segment(false));
	}
	segments.push_back(new Segment(true));
}

Map::~Map() {
	
}

void
Map::printSegments() {
	for (int i = 0; i < 6; ++i) {
		segments[i]->print();
	}
}