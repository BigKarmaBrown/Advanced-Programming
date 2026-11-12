#include "Enemy.h"
#include "Player.h"


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

void Enemy::taketurn(Enemy* enemy, Player* player,NightCycle* cycle)
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 3 + 1;
	randomNumber = randomNumber - 1;

	switch (randomNumber)
	{
	case 0: {
		float damageTemp = enemy->attack(enemy->damage, player, cycle);
		player->takeDamage(damageTemp);
		return;
		break;
	}
		
	case 1:
		chargeAttack(cycle);
		return;
		break;
	case 2:
		brace(player);
		return;
		break;

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
//
//float Enemy::calcDamage(float damage)
//{
//	float tots = damage - defense;
//	tots *
//}
