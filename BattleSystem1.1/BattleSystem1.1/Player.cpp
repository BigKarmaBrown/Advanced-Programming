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

void Player::brace()
{
}

