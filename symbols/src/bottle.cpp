#include <iostream>
#include "../headers/bottle.h"

using namespace std;

Bottle::Bottle() {

}

Bottle::~Bottle() {
	
}

std::string 
Bottle::toString(){
	return "Bottle";
}

void
Bottle::print() {
	cout << "Bottle" << endl;
}