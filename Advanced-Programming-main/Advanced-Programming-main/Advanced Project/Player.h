#pragma once
#include "Enemy.h";
class Player
{
protected:
	float health;
	float maxHealth;
	float damage;
	int range;
	int virtual attackChance;

public:
	virtual float attack(Enemy* enemy);
	void const run(Player* player);
	void brace();
	Player(int damage) : damage(damage){}

};

