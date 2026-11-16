#include "Player.h"
#include "Enemy.h"
float Player::attack(Player* player, Enemy* enemy)
{
	return damage;
}
float Player::attack(Player* player, Enemy* enemy, float Modifier)
{
	return heavyDamage;
}


void Player::takeDamage(float damage)
{
	health = health - damage;
}

void const Player::run(Player* player, GameState* gameState)
{
	health = maxHealth;
	gameState->playerRanBool = true;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------- Health Fully Restored --------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

float Player::brace(Enemy* enemy)
{
	float bracedDamage = enemy->damage / 2;
	return bracedDamage;
}

GameState::battleResult Player::takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle)
{
	return GameState::battleResult::playerMidFight;
}

