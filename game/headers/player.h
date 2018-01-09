#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

class Player {
private:
	std::string playerName;
	std::string playerColor;

public:
	Player();
	~Player();
	Player(std::string name, std::string color);
	std::string getName();
	std::string getColor();
};

#endif
