#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../headers/card.h"
#include "../../helpers/headers/symbolsHelper.h"

using namespace std;

Card::Card() {
	symbol = SymbolHelper::getRandomSymbol();
}

Card::Card(int symbolNumber) {
	symbol = SymbolHelper::getNewSymbol(symbolNumber);
}

Card::~Card() {
	delete symbol;
	symbol = NULL;
}

Symbol*
Card::getSymbol() {
	return symbol;
}

void
Card::print() {
	cout << "\tI'm a card! And my symbol is: ";
	symbol->print();
}