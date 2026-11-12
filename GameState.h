#pragma once
#include "Enemy.h"
using namespace std;
#include <iostream>
class Player;

enum class battleResult{
		playerWin, playerLose, playerRan, playerMidFight
	};
class GameState
{
private: 
	
public:
	int totalTurns = 0;
	bool playersTurn = false;
	

	battleResult GameStart(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle);
	void displayWinner(Player* player, Enemy* enemy);
	GameState(){};
	//friend void displayDead(Player player);
	void displayDead(Player* player);
	static void showTurn(int turn);
	

	
};
