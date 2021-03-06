#include <iostream>
#include "../headers/nullCell.h"

using namespace std;

NullCell::NullCell() {
	index = 0;
}

NullCell::~NullCell() {
	cout << "NullCell destructor called!" << endl;
}

Cell*
NullCell::searchOccupied(int currentIndex){
	return this;
}

Cell* 
NullCell::searchSymbol(Symbol* symbol, int currentIndex){
	return this;
}

Symbol*
NullCell::getSymbol() {
	return NULL;
}

void
NullCell::setIndex(int i) {
	index = 0;
}

int
NullCell::getIndex() {
	return 0;
}

void
NullCell::print() {
	cout << index << endl;
}