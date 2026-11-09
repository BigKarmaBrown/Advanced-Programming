#pragma once
class Enemy;
using namespace std;
#include <iostream>
class Player
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
	virtual void takeTurn(Player* player, Enemy* enemy);
	virtual float attack(Player* player, Enemy* enemy);
	virtual float heavyAttack(Player* player, Enemy* enemy);
	
	friend class GameState;
};