#include <iostream>
#include "../headers/skull.h"

using namespace std;

Skull::Skull() {

}

Skull::~Skull() {
	// cout << "Skull destructor called!" << endl;
}

std::string 
Skull::toString(){
	return "Skull";
}

void
Skull::print() {
	cout << "Skull" << endl;
}