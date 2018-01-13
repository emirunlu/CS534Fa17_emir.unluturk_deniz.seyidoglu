#include <iostream>
#include "../headers/boat.h"

using namespace std;

Boat::Boat() {

}

Boat::~Boat() {
	
}

Cell* 
Boat::searchSymbol(Symbol* symbol){
	cout << "No cells with the symbol: ";
	symbol->print();
	cout << "Moving to boat..\n";
	return this;
}

int 
Boat::getIndex(){
	return index;
}

void
Boat::print() {
	cout << "Boat!" << endl;
}
