#include "Dragon.h"

Dragon::Dragon()
{
	health = 200;
	damage = 20;
}

Dragon::~Dragon()
{
}

float Dragon::attack(float damage, bool hit, Player* player) {
	srand(time(0));
	int randomNumber = rand() % 2 + 1;
	if (randomNumber == 1)
	{
		return 20;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Missed -------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}