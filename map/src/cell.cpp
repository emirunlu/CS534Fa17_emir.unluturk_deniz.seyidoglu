#include <iostream>
#include "../headers/cell.h"
#include "../../helpers/headers/symbolsHelper.h"
#include "../headers/nullCell.h"

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

}

Cell*
Cell::searchOccupied(int currentIndex) {
	if (currentIndex <= index) return new NullCell();
	if (occupied > 0 && occupied <= 2) {
		cout << "FOUND!" << endl;
		occupied++;
		return this;
	}
	else return new NullCell();
}

Cell*
Cell::searchSymbol(Symbol* s, int currentIndex) {
	cout << "\n\n=============================" << endl;
	cout << "Cell currentIndex: " << currentIndex << endl;
	cout << "Cell index: " << index << endl;
	if (currentIndex > index) {
		cout << "Returning nullCell..\n";
		cout << "=============================" << endl;
		return new NullCell();
	}

	cout << "this.symbol is: " << symbol->toString() << endl << "s is: " << s->toString() << endl;
	if (symbol->toString() == s->toString()) {
		cout << "FOUND!" << endl;
		if (occupied < 2) {
			++occupied;
			cout << "Returning this cell! Success!" << endl;
			cout << "=============================" << endl;
			return this;
		}
		cout << "Returning nullCell because this cell is occupied!\n" << endl;
		cout << "=============================" << endl;
		return new NullCell();
	}
	cout << "Returning nullCell because symbols don't match!\n" << endl;
	cout << "=============================" << endl;
	return new NullCell();
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
	if (index >= 0 && index <= 37 ) return index;
	else return 0;
}

Symbol*
Cell::getSymbol() {
	return symbol;
}

int
Cell::getOccupied() {
	return occupied;
}

void
Cell::decreaseOccupied() {
	if (occupied > 0) --occupied;
}

void
Cell::print() {
	cout << index << "-> ";
	symbol->print();
}