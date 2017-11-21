#include <iostream>
#include "../headers/segment.h"

using namespace std;

Segment::Segment() {
	for (int i = 0; i < 6; ++i){
		cells.push_back(new Cell());
	}
}

Segment::~Segment() {
	
}

void
Segment::print() {
	cout << "I'm a segment!" << endl;
	for (int i = 0; i < 6; ++i) {
		cells[i]->print();
	}
}