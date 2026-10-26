#pragma once
class Player;
using namespace std;
#include <iostream>
class Enemy
{
private:
	
	
	//int range;


public:
	virtual float attack(float damage, bool hit, Player* player);
	void run();
	void brace();
	void taketurn(Enemy* enemy, Player* player);
	void takeDamage(float damage);
	float health = 0;
	float damage = 0;
};