#include "Archer.h"



Archer::~Archer()
{
}
float Archer::attack(Player* player, Enemy* enemy) {
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 5 + 1;
	if (randomNumber == 1)
	{
		damage = player->damage;
		enemy->takeDamage(player, damage);
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Hit For " << damage << "---------------------------------------------------- " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return damage;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Missed -------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return 0;
	}
}
float Archer::attack(Player* player, Enemy* enemy, float Modifier)
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 3 + 1;
	if (heavyAttackedUsed == true) {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "---------------------------------------------- Heavy Attack On Cooldown ------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return 0;
	}
	if (randomNumber == 1)
	{
		float damageTotal = player->damage * Modifier;
		enemy->takeDamage(player, damageTotal);
		heavyAttackedUsed = true;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Hit For " << damageTotal << "------------------------------------------------------- " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return damageTotal;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Missed -------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}
battleResult  Archer::run() {
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------ Archer Ran from Fight -------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	heavyAttackedUsed = false;
	health = maxHealth;
	return battleResult::playerRan;
}
battleResult Archer::takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle) {
	string input;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------- Players Turn ------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl << endl << endl;
	cout << "Health: " << player->health << endl;
	cout << "Damage: " << player->damage << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                                     1: Attack" << endl;
	cout << "                                                     2: Brace" << endl;
	cout << "                                                     3: Run" << endl;

	cin >> input;

		if (input == "1" || input == "Attack" || input == "1: Attack" || input == "attack")
		{
			attack(player, enemy);
			
			return battleResult::playerMidFight;
		}
		else if (input == "2" || input == "Brace" || input == "2: Brace" || input == "brace")
		{
			brace(enemy);
			return battleResult::playerMidFight;
		}
		else if (input == "3" || input == "Run" || input == "run" || input == "3: Run" )
		{
			run();
			return battleResult::playerRan;
		}
		else {
			cout << "Invalid Input, Please try again!" << endl;
			return battleResult::playerMidFight;
		}
}