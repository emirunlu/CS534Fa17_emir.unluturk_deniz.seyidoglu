#include <iostream>
#include "../headers/nullCell.h"

using namespace std;

NullCell::NullCell() {

}

NullCell::~NullCell() {
	
}

void
NullCell::print() {
	cout << index << endl;
}