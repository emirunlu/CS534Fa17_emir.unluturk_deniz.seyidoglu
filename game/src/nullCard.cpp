#include "../headers/nullCard.h"

using namespace std;

NullCard::NullCard() {

}

NullCard::NullCard(int symbolNumber) {
	
}

NullCard::~NullCard() {
	
}

Symbol*
NullCard::getSymbol() {
	return NULL;
}

void
NullCard::print() {
	cout << "Null Card! :(";
}