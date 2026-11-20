#pragma once
#include "Barbarian.h"
#include "GameState.h"
#include "NightCycle.h"


Barbarian::~Barbarian()
{
}
float Barbarian::attack(Player* player, Enemy* enemy) {
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 2 + 1;
	if (randomNumber == 1)
	{
		damage = player->damage;
		enemy->takeDamage(player, damage);
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Hit For " << damage << "------------------------------------------------------- " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return damage;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Missed -------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
	return 0;
}
float Barbarian::attack(Player* player, Enemy* enemy, float Modifier)
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
GameState::battleResult  Barbarian::run(Player* player, GameState* gameState) {
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------ Barbarian Ran from Fight -------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	heavyAttackedUsed = false;
	health = maxHealth;
	gameState->playerRan;

	return GameState::battleResult::playerRan;
}
GameState::battleResult Barbarian::takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle, LinkedListMoves* moves)
{
	string input;

	cout << "Health: " << player->health << endl;
	cout << "Damage: " << player->damage << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "1: Attack" << endl;
	cout << "2: Heavy Attack" << endl;
	cout << "3: Brace" << endl;
	cout << "4: Run" << endl;

	cin >> input;

	if (input == "1" || input == "Attack" || input == "1: Attack" || input == "attack")
	{
		attack(player, enemy);
		battleMove* newMove = new battleMove{
			 gameState->totalTurns + 1,"Barbarian", "Attack",
			 hitting == true ? damage : 0
		};
		Link* link = new Link(newMove);
		moves->Insert(link);
		//tree->battleHistory->Insert(newMove);
		hitting = false;
		gameState->totalTurns++;
		return GameState::battleResult::playerMidFight;
	}
	else if (input == "2" || input == "Heavy" || input == "2: Heavy Attack" || input == "H")
	{
		float damage = attack(player, enemy, 2);
		battleMove* newMove = new battleMove{
		 gameState->totalTurns + 1,"Barbarian", "Heavy Attack",
		 hitting == true ? damage : 0
		};
		Link* link = new Link(newMove);
		moves->Insert(link);
		//tree->battleHistory->Insert(newMove);
		//tree->Insert(*newMove, newMove->turnNum);
		hitting = false;
		gameState->totalTurns++;
		return GameState::battleResult::playerMidFight;
	}
	else if (input == "3" || input == "Brace" || input == "3: Brace" || input == "brace")
	{
		brace(enemy);
		battleMove* newMove = new battleMove{
		 gameState->totalTurns + 1,"Barbarian", "Brace",0
		};
		Link* link = new Link(newMove);
		moves->Insert(link);
		//tree->battleHistory->Insert(newMove);
		//tree->Insert(*newMove, newMove->turnNum);
		gameState->totalTurns++;
		return GameState::battleResult::playerMidFight;
	}
	else if (input == "4" || input == "Run" || input == "run" || input == "4: Run")
	{
		run(player, gameState);
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "------------------------------------------------ Barbarain ran from the fight ------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		system("Pause");
		moves->~LinkedListMoves();
		//tree->battleHistory->~PriorityQueue();

		return GameState::battleResult::playerRan;
	}
	else {
		cout << "Invalid Input, Please try again!" << endl;
		gameState->totalTurns++;
		return GameState::battleResult::playerMidFight;
	}

}