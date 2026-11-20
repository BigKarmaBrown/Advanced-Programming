
#pragma once
#include "Enemy.h"
//#include "PriorityQueue.h"

using namespace std;
#include <iostream>
class Player;
class Enemy;
class Tree;
class LinkedListMoves;

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
	static int AccountTurns;
	//static data defined in a class
	battleResult GameStart(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle, LinkedListMoves* moves);
	void displayWinner(Player* player, Enemy* enemy, LinkedListMoves* moves);
	//GameState(){};
	//friend void displayDead(Player player);
	void displayDead(Player* player);
	static void showTurn(int turn);
	void DisplayBattleHistory(LinkedListMoves* moves);
	enum Move {
		attack, heavyAttack, run, brace 
	};

	GameState(LinkedListMoves* moves);
	
};
