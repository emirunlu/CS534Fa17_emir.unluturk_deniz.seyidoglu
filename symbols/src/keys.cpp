#include <iostream>
#include "../headers/keys.h"

using namespace std;

Keys::Keys() {

}

Keys::~Keys() {
	// cout << "Keys destructor called!" << endl;
}

std::string 
Keys::toString(){
	return "Keys";
}

void
Keys::print() {
	cout << "Key" << endl;
}