#include <iostream>
#include "../headers/sword.h"

using namespace std;

Sword::Sword() {

}

Sword::~Sword() {
	// cout << "Sword destructor called!" << endl;
}

std::string 
Sword::toString(){
	return "Sword";
}

void 
Sword::print() {
	cout << "Sword" << endl;
}