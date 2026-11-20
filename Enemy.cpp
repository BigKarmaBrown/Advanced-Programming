#include "Enemy.h"
#include "Player.h"
#include "GameState.h"
#include "NightCycle.h"
//#include "LinkedListMoves.h"
#include "LinkedListMoves.h"
using namespace std;




void Enemy::chargeAttack(NightCycle* cycle)
{
	cycle++;
	cout << "Enemy charged an attack! " << endl;
	//Altering the objects data as if it was a variable
	// using redefined operators. 
	return;
}

float Enemy::brace(Player* player)
{
	//float damageBraced = player->damage / 2;
	cout << "Enemy braced for your hit! " << endl;
	return 0;
	
}

void Enemy::taketurn(Enemy* enemy, Player* player,NightCycle* cycle, GameState* gameState, LinkedListMoves* moves)
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 3 + 1;
	randomNumber = randomNumber - 1;

	switch (randomNumber)
	{
	case 0: {
		enemy->attack(enemy->damage, player, cycle);
		float damageTemp = enemy->attack(enemy->damage, player, cycle);
		player->takeDamage(damageTemp);

		battleMove* newMove = new battleMove{
			 gameState->totalTurns + 1, enemy->displayName(), "attack",hitting == true ? enemy->damage : 0
		};
		Link* link = new Link(newMove);
		moves->Insert(link);
		//tree->battleHistory->Insert(newMove);
		hitting = false;
		gameState->totalTurns++;
		return;
		break;
	}
		
	case 1: {
		chargeAttack(cycle);
		battleMove* newMove = new battleMove{
			 gameState->totalTurns + 1, enemy->displayName(), "Charged attack", 0
		};
		Link* link = new Link(newMove);
		moves->Insert(link);
		//tree->battleHistory->Insert(newMove);
		hitting = false;
		gameState->totalTurns++;
		return;
		break;
	}
	case 2: {
		brace(player);
		battleMove* newMove = new battleMove{
		 gameState->totalTurns + 1, enemy->displayName(), "Braced attack", 0
		};
		Link* link = new Link(newMove);
		moves->Insert(link);
		//tree->battleHistory->Insert(newMove);
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
