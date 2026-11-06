#pragma once
#include "Goblin.h"

Goblin::Goblin()
{
	health = 100;
	damage = 10;
}

Goblin::~Goblin()
{
}
float Goblin::attack(float damage,  Player* player)
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
		return 0;
	}
}

void Goblin::displayPicture()
{
	cout << "             ,      ," << endl;
	cout << "            /(.-""-.)\\\" " << endl;
	cout << "        |\\\  \\\/      \\\/  /|" << endl;
	cout << "        | \\\ / =.  .= \\\ / |" << endl;
	cout << "        \\\( \\\   o\/o   / )/" << endl;
	cout << "         \\\_, '-/  \\\-' ,_/" << endl;
	cout << "           /   \\\__/   \\\" "<< endl;
	cout << "           \\\ \\\__/\\\__/ /" << endl;
	cout << "         ___\\\ \\\|--|/ /___" << endl;
	cout << "       /`    \\\      /    `\\\" "<< endl;
	cout << "      /       '----'       \\\" "<< endl;
	cout << "Health: " << health << endl;
	cout << "Damage: " << damage << endl;

}
