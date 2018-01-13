#include <iostream>
#include "../headers/skull.h"

using namespace std;

Skull::Skull() {

}

Skull::~Skull() {
	
}

std::string 
Skull::toString(){
	return "Skull";
}

void
Skull::print() {
	cout << "Skull" << endl;
}