#pragma once
class Enemy;
using namespace std;
#include "GameState.h"
#include "NightCycle.h"
#include "LinkedListMoves.h"
#include <iostream>
class  Player
{
private:
	 int killed = 0;
	 //A class stores privatised data.
protected:
	
	
	
	int range = 0;
	//int attackChance;
	
public:
	void takeDamage(float damage);
	void const run(Player* player, GameState* gameState);
	float brace(Enemy* enemy);
	float damage = 0;
	float heavyDamage = 0;
	Player(float damage, float health, float maxHealth) : damage(damage), health(health), maxHealth(maxHealth) {
		this->damage = damage;
		this->health = health;
		this->maxHealth = maxHealth;
	}
	//Constructors are used to instantiate objects which may require 
	// additional data which are passed via parameters.

	float maxHealth = 0;
	float health = 0;
	virtual GameState::battleResult takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle, LinkedListMoves* moves);
	virtual float attack(Player* player, Enemy* enemy);
	//A base class has the keyword 'Virtual' which allows subclasses 
	//to override the definition with its own meaning
	virtual float attack(Player* player, Enemy* enemy, float Modifier);
	
	friend class GameState;
	//Another class is stated to be a friend of this class.
};