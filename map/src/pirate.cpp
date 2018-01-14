#include <iostream>
#include "../headers/pirate.h"

using namespace std;

Pirate::Pirate(Cell* loc) {
	currentCell = loc;
}

Pirate::~Pirate() {
	delete currentCell;
}

int
Pirate::getStatus() {
	return currentCell->getIndex();
}

void
Pirate::move(Cell* c) {
	currentCell = c;
}

void 
Pirate::print() {
	cout << "Current Location: ";
	currentCell->print();
}