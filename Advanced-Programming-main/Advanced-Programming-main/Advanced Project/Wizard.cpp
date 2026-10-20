#include "Wizard.h"

Wizard::~Wizard()
{
}
Wizard::Wizard()
{
}
int Wizard::attack(Enemy * enemy) override
{
	srand(time(0)); 
	int randomNumber = rand() % 3 + 1;
	if (randomNumber == 1) 
	{
		return damage;
	}
	else 
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Missed -------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}
//float damage, bool hitW