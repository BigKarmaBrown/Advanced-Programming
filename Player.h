#pragma once
class Enemy;
using namespace std;
#include "GameState.h"
#include "NightCycle.h"
#include "Tree.h"
#include <iostream>
class  Player
{
private:
	/*static*/ int killed = 0;
protected:
	
	
	
	int range = 0;
	//int attackChance;
	
public:
	void takeDamage(float damage);
	void const run(Player* player, GameState* gameState);
	float brace(Enemy* enemy);
	float damage = 0;
	float heavyDamage = 0;
	Player(float damage, float health, float(maxHealth)) : damage(damage), health(health), maxHealth(maxHealth) {
		this->damage = damage;
		this->health = health;
		this->maxHealth = maxHealth;
	}
	float maxHealth = 0;
	float health = 0;
	virtual GameState::battleResult takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle, Tree* tree);
	virtual float attack(Player* player, Enemy* enemy);
	virtual float attack(Player* player, Enemy* enemy, float Modifier);
	
	friend class GameState;
};