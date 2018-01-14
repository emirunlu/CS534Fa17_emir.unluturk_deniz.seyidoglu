#include <iostream>
#include "../headers/hat.h"

using namespace std;

Hat::Hat() {

}

Hat::~Hat() {
	// cout << "Hat destructor called!" << endl;
}

std::string 
Hat::toString(){
	return "Hat";
}

void
Hat::print() {
	cout << "Hat" << endl;
}