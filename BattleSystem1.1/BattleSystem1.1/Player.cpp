#include "Player.h"
#include "Enemy.h"
float Player::attack(Player* player, Enemy* enemy)
{
	return damage;
}
float Player::heavyAttack(Player* player, Enemy* enemy)
{
	return heavyDamage;
}


void Player::takeDamage(float damage)
{
	health = health - damage;
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

void Player::takeTurn(Player* player, Enemy* enemy)
{
}

