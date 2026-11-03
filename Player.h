#pragma once
class Enemy;
using namespace std;
#include <iostream>
class Player
{
private:
	static int killed;
protected:
	
	float maxHealth = 0;
	
	int range = 0;
	//int attackChance;
	static float enemiesSlain;
public:

	void const run(Player* player);
	float brace(Enemy* enemy);
	float damage = 0;
	Player(float damage, float maxHealth) : damage(damage), maxHealth(maxHealth) {}
	float health = 0;
	virtual void takeTurn(Enemy* enemy);
	virtual float attack(Enemy* enemy);
	
	friend class GameState;
};