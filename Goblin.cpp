#pragma once
#include "Goblin.h"
//#include "NightCycle.h"
Goblin::Goblin()
{
	health = 100;
	damage = 10;
}

Goblin::~Goblin()
{
}
float Goblin::attack(float damage, Player* player, NightCycle* cycle) {
	srand(time(0));
	int randomNumber = rand() % 2 + 1;
	float multiplier = 0;
	if (cycle->calcDay(cycle) == true) {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "----------------------------------------------- GOBLIN IS ENRANGED ----------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		multiplier = 1.5;
		cycle++;
	}
	else {
		multiplier = 1;
	}

	if (randomNumber == 1)
	{
		return damage * multiplier;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Missed -------------------------------------------------------" << endl;
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
	cout << endl << endl << endl;


}

string Goblin::displayName()
{
	return "Goblin";
}
