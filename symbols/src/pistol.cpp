#include <iostream>
#include "../headers/pistol.h"

using namespace std;

Pistol::Pistol() {

}

Pistol::~Pistol() {
	
}

std::string 
Pistol::toString(){
	return "Pistol";
}

void
Pistol::print() {
	cout << "Pistol" << endl;
}