#include "Enemy.h"
#include "Player.h"
using namespace std;


float Enemy::attack(float damage, bool hit, Player* player)
{
	return damage;
}

void Enemy::run()
{
}

float Enemy::brace(Player* player)
{
	float damageBraced = player->damage / 2;
	return damageBraced;
}

void Enemy::taketurn(Enemy* enemy, Player* player)
{
	srand(time(0));
	int randomNumber = rand() % 3 + 1;
	randomNumber = randomNumber - 1;

	switch (randomNumber)
	{
	case 0:
		enemy->attack(10, true ,player);
		break;
	case 1:
		run();
		break;
	case 2:
		brace(player);
		break;

	default:
		cout << "------------------------------ Enemy Took an invalid turn ---------------------------" << endl;
	}
}

void Enemy::takeDamage(float damage)
{
	health = health - damage;
}
