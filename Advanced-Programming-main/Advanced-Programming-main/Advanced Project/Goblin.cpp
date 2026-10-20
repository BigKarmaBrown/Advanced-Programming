#include "Goblin.h"

Goblin::Goblin()
{
}

Goblin::~Goblin()
{
}
Enemy::attack() override 
{
	srand(time(0));
	int randomNumber = rand() % 10 + 1;
	if (randomNumber <= 6)
	{
		return 10, true;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "---------------------------------------------- Goblins Attack Missed ---------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}
Goblin Health(Enemy* enemy) {
	enemy->health = 100;
}