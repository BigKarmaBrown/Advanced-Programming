#include "Enemy.h"
#include "Player.h"
using namespace std;


float Enemy::attack(float damage, Player* player)
{

	return damage;
}

void Enemy::run()
{
	cout << "Enemey attempted to flee the fight but it failed! " << endl;

	return;
}

float Enemy::brace(Player* player)
{
	//float damageBraced = player->damage / 2;
	cout << "Enemy braced for your hit! " << endl;
	return 0;
	
}

void Enemy::taketurn(Enemy* enemy, Player* player)
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 3 + 1;
	randomNumber = randomNumber - 1;

	switch (randomNumber)
	{
	case 0: {
		//cout << "ENEMY HIT YOU FOR " << enemy->damage << " DAMAGE !!" << endl;
				enemy->attack(enemy->damage, player);
				float damageTemp = enemy->attack(enemy->damage, player);
				player->takeDamage(damageTemp);
				return;
				break;
	}
		
	case 1:
		run();
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

void Enemy::takeDamage(Player* player)
{
	health = health - player->damage;
}

void Enemy::displayPicture()
{
	cout << "enemy picture here" << endl;
}
