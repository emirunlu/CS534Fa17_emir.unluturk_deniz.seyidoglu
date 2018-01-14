#include "../headers/gameHelper.h"

GameHelper::GameHelper(Game* g) {
	game = g;
}

GameHelper::~GameHelper() {
}

void
GameHelper::addPlayer(std::string name, std::string color) {
	players.push_back(new Player(name, color, game));
}

void
GameHelper::setPlayer(Player * p) {
	player = p;
}

void
GameHelper::updatePlayerTurn(int turn) {
	int t = turn - 1;
	for (unsigned int i = 0; i < players.size(); ++i) {
		if (t == i) currentPlayer = players.at(i);
	}
}

Player*
GameHelper::getCurrentPlayer() {
	return currentPlayer;
}

vector<Player*>
GameHelper::getPlayers() {
	return players;
}

void
GameHelper::setPlayerTurn(Player * p) {
	currentPlayer = p;
}