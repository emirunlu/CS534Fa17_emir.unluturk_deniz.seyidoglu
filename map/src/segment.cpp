#include <iostream>
#include "../headers/segment.h"

using namespace std;

Segment::Segment(bool lastSegment) {
	for (int i = 0; i < 6; ++i){
		cells.push_back(new Cell());
	}
	if (lastSegment) {
		cells.push_back(new Boat());
	}
}

Segment::~Segment() {
	
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