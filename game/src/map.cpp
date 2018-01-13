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

Cell*
Map::searchSymbol(Symbol* symbol) {
	for (int i = 0; i < segments.size(); ++i) {
		Cell* c = segments[i]->searchSymbol(symbol);
		if (c) {
			cout << "Found in segment " << (i+1) << " cell " << (c->getIndex()) << endl;
			return c;
		}
	}
}

void
Map::print() {
	for (int i = 0; i < 6; ++i) {		
		cout << i + 1;
		cout << "th segment \n";
		segments[i]->print();
		cout << endl;
	}
}

Cell*
Map::getFirstCell() {
	return segments[0]->getFirstCell();
}