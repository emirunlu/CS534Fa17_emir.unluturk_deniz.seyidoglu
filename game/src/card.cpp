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
	cout << "Card destructor called!" << endl;
	delete symbol;
	symbol = nullptr;
}

Symbol*
Card::getSymbol() {
	return symbol;
}

void
Card::print() {
	cout << "Card: ";
	symbol->print();
}