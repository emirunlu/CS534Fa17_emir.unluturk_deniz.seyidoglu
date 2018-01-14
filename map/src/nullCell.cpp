#include <iostream>
#include "../headers/nullCell.h"

using namespace std;

NullCell::NullCell() {

}

NullCell::~NullCell() {
	
}

Cell* 
NullCell::searchOccupied(int currentIndex){
	return NULL;
}

Cell* 
NullCell::searchSymbol(Symbol* symbol, int currentIndex){
	return NULL;
}

void
NullCell::setIndex(int i) {
	index = 0;
}

int
NullCell::getIndex() {
	return index;
}

void
NullCell::print() {
	cout << index << endl;
}