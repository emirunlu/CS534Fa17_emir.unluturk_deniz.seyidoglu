#include <iostream>
#include <math.h>
#include "../headers/map.h"

using namespace std;

Map::Map() {
	for (int i = 0; i < 5; ++i) {
		segments.push_back(new Segment(false));
	}
	segments.push_back(new Segment(true));

  	for (int i = 0; i < segments.size(); ++i) {
  		std::vector<Cell*> cells = segments[i]->getCells();
  		for (int j = 0; j < 6; ++j) {
  			cells[j]->setIndex(i * 6 + j + 1);
  		}
  	}
}

Map::~Map() {
	
}

Cell* 
Map::searchOccupied(int currentIndex){
	cout << "Searching in map.." << endl;
	int i;
	if (currentIndex != 0){
		i = segments.size() - (ceil(currentIndex / 6.0) - 1) - 1;
	} else {
		i = segments.size() - 1;
	}
	cout << "i: " << i << endl;
	for (;i >= 0; --i) {
		Cell* c = segments[i]->searchOccupied(currentIndex);
		if (c->getIndex() > currentIndex) {
			cout << "Found in segment " << (i+1) << " cell " << (c->getIndex()) << endl;
			return c;
		}
	}
	return new NullCell();
}

Cell*
Map::searchSymbol(Symbol* symbol, int currentIndex) {
	int i;
	if (currentIndex != 0){
		i = ceil(currentIndex / 6.0) - 1;
	} else {
		i = 0;
	}
	
	cout << "Map index: " << i << endl;
	cout << "Map currentIndex: " << currentIndex << endl;

	for (;i < segments.size(); ++i) {
		Cell* c = segments[i]->searchSymbol(symbol, currentIndex);
		if (c->getIndex() > currentIndex) {
			cout << "Found in segment " << (i+1) << " cell " << (c->getIndex()) << endl;
			return c;
		}
	}
	return new NullCell();
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