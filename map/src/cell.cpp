#include <iostream>
#include "../headers/cell.h"
#include "../../helpers/headers/symbolsHelper.h"

using namespace std;

Cell::Cell() {
	symbol = SymbolHelper::getRandomSymbol();
	occupied = 0;
}

Cell::Cell(int symbolNumber) {
	symbol = SymbolHelper::getNewSymbol(symbolNumber);
	occupied = 0;
}

Cell::~Cell() {
	delete symbol;
}

Cell*
Cell::searchOccupied(int currentIndex) {
	cout << "currentIndex: " << currentIndex << endl;
	cout << "index: " << index << endl;
	if (currentIndex <= index) return NULL;
	if (occupied > 0 && occupied <= 2) {
		cout << "FOUND!" << endl;
		occupied++;
		return this;
	}
	else return NULL;
}

Cell*
Cell::searchSymbol(Symbol* s, int currentIndex) {
	if (currentIndex > index){
		return NULL;
	}
	if (symbol->toString() == s->toString()) {
		if (occupied < 2) {
			++occupied;
			return this;
		}
		return NULL;
	}
	else return NULL;
}

void 
Cell::setSymbolCell(Symbol* sym) {
	symbol = sym;
}

void
Cell::setIndex(int i) {
	index = i;
}

int
Cell::getIndex() {
	return index;
}

int
Cell::getOccupied() {
	return occupied;
}

void
Cell::print() {
	cout << index << "-> ";
	symbol->print();
}