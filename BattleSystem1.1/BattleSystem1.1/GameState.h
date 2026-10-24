#pragma once
#include "Enemy.h"
#include "Player.h"
using namespace std;
#include <iostream>


class GameState
{
private: 
	
public:
	int totalTurns;
	bool playersTurn;

	void GameStart(Player* player, Enemy* enemy);
	GameState(){};

};
