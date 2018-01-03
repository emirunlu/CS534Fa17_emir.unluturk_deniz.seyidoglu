#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
private:
	std::string playerName;

public:
	Player();
	~Player();
	Player(std::string name);
	std::string getName();
};

#endif
