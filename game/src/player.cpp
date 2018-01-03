#include <iostream>
#include <string>

#include "../headers/player.h"


Player::Player() {
	playerName = "Default";
}

Player::Player(std::string name) {
	playerName = name;
}

Player::~Player() {

}

std::string
Player::getName() {
	return playerName;
}