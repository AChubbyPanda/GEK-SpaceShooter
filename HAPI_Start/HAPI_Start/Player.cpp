#include "Player.h"

const void Player::TakeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}

//bool Player::IsDead()
//{
//	return true;
//}

const int Player::GetScore()
{
	return p_Score;
}

void Player::GetInPut()
{
	return ControlInPut();
}

void Player::Update()
{
}

ESide Player::GetSide() const
{
	return ESide::eSidePlayer;
}

Player::Player(std::string EntityName, int playerHealth, int playerDamage)
	: Entity(EntityName)
	, p_Score{ 0 }
{
	m_Health = playerHealth;
	m_Damage = playerDamage;
}

Player::~Player()
{
}