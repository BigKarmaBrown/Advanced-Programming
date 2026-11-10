#pragma once
#include "NightCycle.h"
class Player;
using namespace std;
#include <iostream>
class Enemy
{
private:
	
	
	//int range;


public:
	virtual float attack(float damage, Player* player, NightCycle* cycle);
	void chargeAttack(NightCycle* cycle);
	static float brace(Player* player);
	void taketurn(Enemy* enemy, Player* player, NightCycle* cycle);
	 void takeDamage(Player* player, float damage);
	 virtual void displayPicture();
	float health = 0;
	float damage = 0;
	float defense = 0;
	float calcDamage(float damage);
};