#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../headers/symbolsHelper.h"

using namespace std;

Symbol*
SymbolHelper::getRandomSymbol() {
	srand (time(NULL));
	try{
		int random = rand()%6;
		return getNewSymbol(random);
	} catch (int e) {
		cout << "Random seed generator is wrong. Created number: " << e << endl;
	}
	//TODO: Null symbol object?
	return NULL;
}

Symbol*
SymbolHelper::getNewSymbol(int number){
	switch(number){
		case 0:
			return new Bottle();
		case 1:
			return new Hat();
		case 2:
			return new Keys();
		case 3:
			return new Pistol();
		case 4:
			return new Skull();
		case 5:
			return new Sword();
		default:
			throw number;
	}
}