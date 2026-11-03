#include "Player.h"
#include "Enemy.h"
float Player::attack(Enemy* enemy)
{
	return damage;
}


void const Player::run(Player* player)
{
	health = maxHealth;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------- Health Fully Restored --------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

float Player::brace(Enemy* enemy)
{
	float bracedDamage = enemy->damage / 2;
	return bracedDamage;
}

void Player::takeTurn(Enemy* enemy)
{
}

