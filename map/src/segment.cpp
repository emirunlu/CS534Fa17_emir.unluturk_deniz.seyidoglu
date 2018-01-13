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
  	
  	for (int i = 0; i < cells.size(); ++i) {
  		cells[i]->setIndex(i);
  	}

	if (lastSegment) {
		cells.push_back(new Boat());
	}
}

Segment::~Segment() {
	for (int i = 0; i < cells.size(); ++i){
		delete cells[i];
	}
	cells.clear();
}

Cell*
Segment::getFirstCell() {
	return cells[0];
}

void
Segment::print() {
	cout << "I'm a segment!" << endl;
	for (int i = 0; i < cells.size(); ++i) {
		cout << i + 1;
		cout << "th cell:";
		cells[i]->print();
	}
}