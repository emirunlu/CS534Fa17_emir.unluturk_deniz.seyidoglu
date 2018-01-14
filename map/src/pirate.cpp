#include <iostream>
#include "../headers/pirate.h"

using namespace std;

Pirate::Pirate(Cell* loc) {
	currentCell = loc;
}

Pirate::~Pirate() {
	cout << "Pirate destructor called!" << endl;
	delete currentCell;
	currentCell = nullptr;
}

int
Pirate::getStatus() {
	int loc = currentCell->getIndex();
	if (loc <= 37 && loc >= 0) return currentCell->getIndex();
	// This should happen but it does, i don't know why!
	else return 0;
}

void
Pirate::move(Cell* c) {
	currentCell = c;
}

Cell*
Pirate::getCell() {
	return currentCell;
}

void 
Pirate::print() {
	cout << "Current Location: ";
	currentCell->print();
}