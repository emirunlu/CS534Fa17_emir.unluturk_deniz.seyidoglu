#ifndef GAMEHELPER_H
#define GAMEHELPER_H

#include "../../game/headers/player.h"
#include <vector>

using namespace std;

class GameHelper {
public:
	GameHelper();
	GameHelper(string name, string color);
	~GameHelper();

	void addPlayer(string name, string color);
	void setPlayer(Player* p);
	void updatePlayerTurn(int turn);
	Player* getCurrentPlayer();
	vector<Player*> getPlayers();

private:
	Player* player;
	Player* currentPlayer;
	vector<Player*> Players;

	void setPlayerTurn(Player* p);
};

#endif