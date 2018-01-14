#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include "../headers/segment.h"

using namespace std;

Segment::Segment(bool lastSegment) {
	for (int i = 0; i < 6; ++i) {
		cells.push_back(new Cell(i));
	}
  	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	shuffle (cells.begin(), cells.end(), std::default_random_engine(seed));

	if (lastSegment) {
		cells.push_back(new Boat());
	}
}

Segment::~Segment() {
}

Cell* 
Segment::searchOccupied(int currentIndex){
	cout << "Searching in segment.." << endl;
	Cell* foundCell = new NullCell();
	for (int i = cells.size() - 1; i >= 0; --i) {
		foundCell = cells[i]->searchOccupied(currentIndex);
		if (foundCell->getSymbol() && foundCell->getIndex() > currentIndex) {
			return foundCell;
		}
	}
	return new NullCell();
}

Cell*
Segment::searchSymbol(Symbol* symbol, int currentIndex) {
	cout << "Segment current index: " << currentIndex << endl;
	Cell* foundCell = new NullCell();
	for (int i = 0; i < cells.size(); ++i) {
		foundCell = cells[i]->searchSymbol(symbol, currentIndex);
		if (foundCell->getSymbol() && foundCell->getIndex() > currentIndex) {
			cout << "Segment found cell index: " << foundCell->getIndex() << endl;
			return foundCell;
		}
	}
	return new NullCell();
}

std::vector<Cell*>
Segment::getCells() {
	return cells;
}

Cell*
Segment::getFirstCell() {
	return cells[0];
}

void
Segment::print() {
	for (int i = 0; i < cells.size(); ++i) {
		cout << i + 1;
		cout << "th cell: ";
		cells[i]->print();
	}
}