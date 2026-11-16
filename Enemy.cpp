#include "Enemy.h"
#include "Player.h"
#include "GameState.h"
#include "NightCycle.h"

using namespace std;


float Enemy::attack(float damage, Player* player,NightCycle* cycle)
{
	
	return damage;
}

void Enemy::chargeAttack(NightCycle* cycle)
{
	cycle++;
	cout << "Enemy charged an attack! " << endl;

	return;
}

float Enemy::brace(Player* player)
{
	//float damageBraced = player->damage / 2;
	cout << "Enemy braced for your hit! " << endl;
	return 0;
	
}

void Enemy::taketurn(Enemy* enemy, Player* player,NightCycle* cycle, GameState* gameState)
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 3 + 1;
	randomNumber = randomNumber - 1;

	switch (randomNumber)
	{
	case 0: {
		float damageTemp = enemy->attack(enemy->damage, player, cycle);
		player->takeDamage(damageTemp);

		GameState::BattleMove* newMove = new GameState::BattleMove{
			 gameState->totalTurns + 1, enemy->displayName(), "attack",hitting == true ? enemy->damage : 0
		};
		gameState->battleHistory->Insert(newMove);
		hitting = false;
		gameState->totalTurns++;
		return;
		break;
	}
		
	case 1: {
		chargeAttack(cycle);
		GameState::BattleMove* newMove = new GameState::BattleMove{
			 gameState->totalTurns + 1, enemy->displayName(), "Charged attack", 0
		};
		gameState->battleHistory->Insert(newMove);
		hitting = false;
		gameState->totalTurns++;
		return;
		break;
	}
	case 2: {
		brace(player);
		GameState::BattleMove* newMove = new GameState::BattleMove{
		 gameState->totalTurns + 1, enemy->displayName(), "Braced attack", 0
		};
		gameState->battleHistory->Insert(newMove);
		hitting = false;
		gameState->totalTurns++;
		return;
		break;
	}
	default:
		cout << "------------------------------ Enemy Took an invalid turn ---------------------------" << endl;
	}
}

void Enemy::takeDamage(Player* player, float damage)
{
	
	health = health - damage;
}

void Enemy::displayPicture()
{
	cout << "enemy picture here" << endl;
}
string Enemy::displayName()
{
	return "Enemy got no name";
}
//
//float Enemy::calcDamage(float damage)
//{
//	float tots = damage - defense;
//	tots *
//}
