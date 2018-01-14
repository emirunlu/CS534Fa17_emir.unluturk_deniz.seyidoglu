#include <iostream>
#include "../headers/boat.h"

using namespace std;

Boat::Boat() {
	index = 37;
}

Boat::~Boat() {
	cout << "Boat destructor called!" << endl;
}

Cell* 
Boat::searchOccupied(int currentIndex){
	return this;
}

Cell* 
Boat::searchSymbol(Symbol* symbol, int currentIndex){
	cout << "No cells with the symbol: ";
	symbol->print();
	cout << "Moving to boat..\n";
	return this;
}

Symbol*
Boat::getSymbol() {
	return NULL;
}

void
Boat::setIndex(int i) {
	index = 37;
}

int 
Boat::getIndex(){
	return 37;
}

void
Boat::print() {
	cout << "Boat!" << endl;
}
