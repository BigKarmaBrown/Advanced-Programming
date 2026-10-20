#pragma once
class Player
{
private:
	float health;
	float damage;
	int range;
	int virtual attackChance;

public:
	void attack(float damage, bool hit);
	void run();
	void brace();

};

