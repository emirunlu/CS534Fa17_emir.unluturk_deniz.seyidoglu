#include "../headers/nullCard.h"

using namespace std;

NullCard::NullCard() {

}

NullCard::NullCard(int symbolNumber) {
	
}

NullCard::~NullCard() {
	cout << "NullCard destructor called!" << endl;
}

Symbol*
NullCard::getSymbol() {
	return NULL;
}

void
NullCard::print() {
	cout << "Null Card! :(";
}