#include <iostream>
#include <string>

#include "../headers/player.h"
#include "../../map/headers/nullCell.h"

Player::Player() {
	playerName = "Default";
	playerColor = "DefaultColor";
}

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
	for (int i = 0; i < cardList.size(); ++i) {
		delete cardList[i];
	}
	for (int i = 0; i < pirateList.size(); ++i) {
		delete pirateList[i];
	}
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

void 
Player::playCard(int cardIndex, int pirateIndex) {
	Symbol* symbol = cardList[cardIndex - 1]->getSymbol();
	cardList.erase(cardList.begin() + cardIndex - 1);
	Cell* c = game->getMap()->searchSymbol(symbol);
	movePirate(pirateIndex, c);
}

void
Player::movePirate(int i, Cell* c) {
	pirateList[i - 1]->move(c);
}

void 
Player::getCard() {
	if (cardList.size() > 6) {
		cout << "Maximum card reached!" << endl;
		return;
	} else {
		cardList.push_back(game->getCard());
	}
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