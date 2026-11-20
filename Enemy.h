#pragma once
class NightCycle;// "NightCycle.h"
//#include "GameState.h"
class Player;
class GameState;
//class NightCycle;
class LinkedListMoves;
//#include "LinkedListMoves.h"
using namespace std;
#include <iostream>
class Enemy
{
private:
	
	
	//int range;
protected:
	//virtual string name;

public:
	virtual float attack(float damage, Player* player, NightCycle* cycle) = 0;
	void chargeAttack(NightCycle* cycle);
	static float brace(Player* player);
	void taketurn(Enemy* enemy, Player* player, NightCycle* cycle, GameState* gameState, LinkedListMoves* moves);
	 void takeDamage(Player* player, float damage);
	 virtual void displayPicture();
	 virtual string displayName();
	float health = 0;
	float damage = 0;
	float defense = 0;
	bool hitting = false;
	 
};