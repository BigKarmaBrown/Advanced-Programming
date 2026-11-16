
#pragma once
#include "Enemy.h"
#include "PriorityQueue.h"
using namespace std;
#include <iostream>
class Player;


class GameState
{
private: 
	
public:
	int totalTurns = 0;
	bool playersTurn = false;
	bool playerRanBool = false;

enum battleResult{
		playerWin, playerLose, playerRan, playerMidFight, playerNotInFight
	};

	battleResult GameStart(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle);
	void displayWinner(Player* player, Enemy* enemy);
	GameState(){};
	//friend void displayDead(Player player);
	void displayDead(Player* player);
	static void showTurn(int turn);
	
	enum Move {
		attack, heavyAttack, run, brace 
	};
	struct BattleMove {
		int turnNum;
		string person;
		Move move;
		float damage;
	};
	PriorityQueue<BattleMove>* battleHistory;
};
