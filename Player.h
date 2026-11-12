#pragma once
class Enemy;
using namespace std;
#include "GameState.h"
#include "NightCycle.h"
#include <iostream>
class  Player
{
private:
	/*static*/ int killed = 0;
protected:
	
	float maxHealth = 0;
	
	int range = 0;
	//int attackChance;
	
public:
	void takeDamage(float damage);
	void const run(Player* player);
	float brace(Enemy* enemy);
	float damage = 0;
	float heavyDamage = 0;
	Player(float damage, float health) : damage(damage), health(health) {
		this->damage = damage;
		this->health = health;
	}
	float health = 0;
	virtual battleResult takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle);
	virtual float attack(Player* player, Enemy* enemy);
	virtual float attack(Player* player, Enemy* enemy, float Modifier);
	
	friend class GameState;
};