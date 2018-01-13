#include <iostream>
#include "../headers/nullCell.h"

using namespace std;

NullCell::NullCell() {

}

NullCell::~NullCell() {
	
}

void
NullCell::print() {
	cout << "\tI'm a null cell and my index is: " << index << endl;
}