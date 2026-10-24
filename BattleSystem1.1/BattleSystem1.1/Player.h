#pragma once
class Enemy;
using namespace std;
#include <iostream>
class Player
{
protected:
	
	float maxHealth = 0;
	float damage = 0;
	int range = 0;
	//int attackChance;

public:
	virtual float attack(Enemy* enemy);
	void const run(Player* player);
	void brace();

	Player(float damage, float maxHealth) : damage(damage), maxHealth(maxHealth) {}
	float health = 0;
};