#pragma once
class Player;
using namespace std;
#include <iostream>
class Enemy
{
private:
	
	
	//int range;


public:
	virtual float attack(float damage, Player* player);
	void run();
	static float brace(Player* player);
	void taketurn(Enemy* enemy, Player* player);
	 void takeDamage(Player* player);
	 virtual void displayPicture();
	float health = 0;
	float damage = 0;
};