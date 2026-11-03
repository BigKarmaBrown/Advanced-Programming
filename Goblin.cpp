#include "Goblin.h"

Goblin::Goblin()
{
	health = 100;
	damage = 10;
}

Goblin::~Goblin()
{
}
float Goblin::attack(float damage, bool hit, Player* player)
{
	srand(time(0));
	int randomNumber = rand() % 10 + 1;
	if (randomNumber <= 6)
	{
		return 10;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "---------------------------------------------- Goblins Attack Missed ---------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}
