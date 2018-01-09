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

}

std::string
Player::getName() {
	return playerName;
}

std::string
Player::getColor() {
	return playerColor;
}
