#pragma once
#include "Player.h"
using namespace std;
#include <iostream>
class Enemy
{
private:
	
	float damage;
	int range;


public:
	virtual float attack(float damage, bool hit, Player* player);
	void run();
	void brace();
	void taketurn(Enemy* enemy, Player* player);
	float health;
};