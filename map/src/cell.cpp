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

void
Cell::print() {
	cout << "\tI'm a cell! And my symbol is: ";
	symbol->print();
}

void 
Cell::setSymbolCell(Symbol* sym) {
	symbol = sym;
}

void
Cell::setIndex(int i) {
	index = i;
}