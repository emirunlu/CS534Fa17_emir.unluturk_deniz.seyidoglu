#include <iostream>
#include "../headers/map.h"

using namespace std;

Map::Map() {
	for (int i = 0; i < 5; ++i) {
		segments.push_back(new Segment(false));
	}
	segments.push_back(new Segment(true));
}

Map::~Map() {
	for (int i = 0; i < segments.size(); ++i) {
		delete segments[i];
	}
	segments.clear();
}

void
Map::printSegments() {
	for (int i = 0; i < 6; ++i) {
		segments[i]->print();
	}
}

Cell*
Map::getFirstCell() {
	return segments[0]->getFirstCell();
}