#include <iostream>
#include <string>

#include "../headers/player.h"
#include "../../map/headers/nullCell.h"

Player::Player() {
	playerName = "Default";
	playerColor = "DefaultColor";
}

Player::Player(std::string name, std::string color, Game* game) {
	playerName = name;
	playerColor = color;
	for (int i = 0; i < 6; ++i) {
		pirateList.push_back(new Pirate(new NullCell()));	
	}
	std::vector<Card*> c = game->getCards(6);
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
Player::movePirate(int i, Cell* c) {
	pirateList[i]->move(c);
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
	cout << "========================\n";
	cout << "Name: " << this->getName() << endl;
	cout << "Color: " << this->getColor() << endl;
	cout << "Cards in hand:" << endl;
	for (Card* card : cardList){
		card->print();
	}
	cout << "Pirate information" << endl;
	for (Pirate* pirate : pirateList) {
		pirate->print();
	}

}