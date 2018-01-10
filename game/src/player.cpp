#include <iostream>
#include <string>

#include "../headers/player.h"

Player::Player() {
	playerName = "Default";
	playerColor = "DefaultColor";
}

Player::Player(std::string name, std::string color) {
	playerName = name;
	playerColor = color;
}

Player::~Player() {
	cardList.clear();
	std::cout << "Deleted Players hand" << std::endl;
	pirateList.clear();
	std::cout << "Deleted Players piratelist" << std::endl;

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
	cardList.push_back(c);
}

void
Player::addPirate(Pirate* p) {
	pirateList.push_back(p);
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