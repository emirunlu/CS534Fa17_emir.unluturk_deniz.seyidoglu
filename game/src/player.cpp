#include <iostream>
#include <string>

#include "../headers/player.h"
#include "../../map/headers/nullCell.h"

Player::Player(std::string name, std::string color, Game* g) {
	playerName = name;
	playerColor = color;
	game = g;
	for (int i = 0; i < 6; ++i) {
		pirateList.push_back(new Pirate(new NullCell()));	
	}
	std::vector<Card*> c = g->getCards(6);
	cardList.insert(cardList.end(), c.begin(), c.end());
}

Player::~Player() {
	
}

std::string
Player::getName() {
	return playerName;
}

std::string
Player::getColor() {
	return playerColor;
}

void
Player::addCard(Card* c) {
	this->cardList.push_back(c);
}

void
Player::addPirate(Pirate* p) {
	this->pirateList.push_back(p);
}

std::vector<Card*>
Player::getHand() {
	return cardList;
}

Card*
Player::getCardInHand(int i) {
	return cardList.at(i);
}

std::vector<Pirate*>
Player::getPirateList() {
	return pirateList;
}

Pirate*
Player::getPirateInList(int i) {
	return pirateList.at(i);
}

bool
Player::checkStatus() {
	for(auto pirate : pirateList) {
		if (pirate->getStatus() != 37) {
			return false;
		}
	}
	return true;
}

void 
Player::playCard(int cardIndex, int pirateIndex) {
	Symbol* symbol = cardList[cardIndex - 1]->getSymbol();
	int currentIndex = pirateList[pirateIndex - 1]->getStatus();
	cout << "\n\n\nPlayer currentIndex:" << currentIndex << endl;
	Cell* c = game->getMap()->searchSymbol(symbol, currentIndex);
	if (c->getIndex() > currentIndex){
		cout << "\n\n\nMoving pirate to: " << c->getIndex() << "\nPrev index was: " << currentIndex << endl << endl << endl;
		pirateList[pirateIndex - 1]->getCell()->decreaseOccupied();
		pirateList[pirateIndex - 1]->move(c);
		cardList.erase(cardList.begin() + cardIndex - 1);
	}
	else {
		cout << "\n\n\nFound cell: " << c->getIndex() << endl << endl << endl;
		cout << "No cells that are closer to boat!\n\n";
		return;
	}
}

void
Player::moveBack(int pirateIndex) {
	int currentIndex = pirateList[pirateIndex - 1]->getStatus();
	Cell* c = game->getMap()->searchOccupied(currentIndex);
	c->print();
	if (c->getIndex() > 0) {
		pirateList[pirateIndex - 1]->move(c);
		int occupied = c->getOccupied();
		int i = 0;
		while(i < occupied){
			getCard();	
			++i;	
		}
	}
	else {
		cout << "Can't go back!" << endl;
		return;
	}
}

void 
Player::getCard() {
	Card* card = game->getCard();
	if (card){
		cardList.push_back(card);
	} else {
		game->shuffleOldCards();
		getCard();
	}
}

void
Player::printCompact() {
	cout << "\n========================\n";
	cout << " Player Information" << endl;
	cout << "========================\n\n";
	cout << "Name: " << this->getName() << endl;
	cout << "Color: " << this->getColor() << endl;
}

void 
Player::print() {
	cout << "\n========================\n";
	cout << " Player Information" << endl;
	cout << "========================\n\n";
	cout << "Name: " << this->getName() << endl;
	cout << "Color: " << this->getColor() << endl;
	cout << "\nCards in hand" << endl;

	for (int i = 0; i < cardList.size(); ++i){
		cout << (i + 1) << "  ";
		cardList[i]->print();
	}
	cout << "\nPirate information" << endl;
	for (int i = 0; i < pirateList.size(); ++i){
		pirateList[i]->print();
	}
	
	cout << endl << endl;
}