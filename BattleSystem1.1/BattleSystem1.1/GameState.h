#pragma once
#include "Enemy.h"
#include "Player.h"
using namespace std;
#include <iostream>


class GameState
{
private: 
	
public:
	int totalTurns = 0;
	bool playersTurn = false;

	void GameStart(Player* player, Enemy* enemy);
	void displayWinner(Player* player, Enemy* enemy);
	GameState(){};
	//friend void displayDead(Player player);
	void displayDead(Player* player);
	

	
};
