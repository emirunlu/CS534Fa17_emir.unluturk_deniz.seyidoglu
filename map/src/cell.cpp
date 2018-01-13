#include <iostream>
#include "../headers/cell.h"
#include "../../helpers/headers/symbolsHelper.h"

using namespace std;

Cell::Cell() {
	symbol = SymbolHelper::getRandomSymbol();
}

Cell::Cell(int symbolNumber) {
	symbol = SymbolHelper::getNewSymbol(symbolNumber);
}

Cell::~Cell() {
	delete symbol;
}

Cell*
Cell::searchSymbol(Symbol* s) {
	if (symbol->toString() == s->toString()) {
		if (!occupied) {
			occupied = true;
			return this;
		}
		return NULL;
	}
	else return NULL;
}

void
Cell::setOccupied(bool cond) {
	occupied = cond;
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

void
Cell::print() {
	cout << index << "-> ";
	symbol->print();
}