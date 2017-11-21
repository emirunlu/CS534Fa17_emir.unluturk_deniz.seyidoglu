#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "../headers/card.h"
#include "../../symbols/headers/helper.h"

using namespace std;

Card::Card() {
	symbol = Helper::getRandomSymbol();
}

Card::~Card() {
	
}

Symbol*
Card::getSymbol() {
	return symbol;
}