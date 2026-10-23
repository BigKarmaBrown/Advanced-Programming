#pragma once
#include "Enemy.h";
using namespace std;
#include <iostream>
class Player
{
protected:
	
	float maxHealth;
	float damage;
	int range;
	int attackChance;

public:
	virtual float attack(Enemy* enemy);
	void const run(Player* player);
	void brace();
	Player(int damage) : damage(damage) {}
	float health;
};