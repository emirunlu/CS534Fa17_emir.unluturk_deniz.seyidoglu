#include <iostream>
#include "../headers/hat.h"

using namespace std;

Hat::Hat() {

}

Hat::~Hat() {
	
}

std::string 
Hat::toString(){
	return "Hat";
}

void
Hat::print() {
	cout << "Hat" << endl;
}