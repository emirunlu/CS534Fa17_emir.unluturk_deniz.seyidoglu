#include <iostream>
#include "../headers/bottle.h"

using namespace std;

Bottle::Bottle() {

}

Bottle::~Bottle() {
	// cout << "Bottle destructor called!" << endl;
}

std::string 
Bottle::toString(){
	return "Bottle";
}

void
Bottle::print() {
	cout << "Bottle" << endl;
}