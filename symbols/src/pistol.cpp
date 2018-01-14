#include <iostream>
#include "../headers/pistol.h"

using namespace std;

Pistol::Pistol() {

}

Pistol::~Pistol() {
	// cout << "Pistol destructor called!" << endl;
}

std::string 
Pistol::toString(){
	return "Pistol";
}

void
Pistol::print() {
	cout << "Pistol" << endl;
}