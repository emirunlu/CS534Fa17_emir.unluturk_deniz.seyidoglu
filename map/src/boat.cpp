#include <iostream>
#include "../headers/boat.h"

using namespace std;

Boat::Boat() {

}

Boat::~Boat() {
	
}

Cell* 
Boat::searchOccupied(int currentIndex){
	return NULL;
}

Cell* 
Boat::searchSymbol(Symbol* symbol, int currentIndex){
	cout << "No cells with the symbol: ";
	symbol->print();
	cout << "Moving to boat..\n";
	return this;
}

void
Boat::setIndex(int i) {
	index = 37;
}

int 
Boat::getIndex(){
	return index;
}

void
Boat::print() {
	cout << "Boat!" << endl;
}
