#include "Player.h"

const void Player::TakeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}

const int Player::GetScore()
{
	return p_Score;
}

void Player::GetInPut()
{
	return ControlInPut();
}

Player::Player(const std::string p_Name, int p_PosX, int p_PosY, int p_Health, int p_Damage, ESide p_Side)
	:p_Score{ 0 }
{
	m_Name = p_Name;
	m_PosX = p_PosX;
	m_PosY = p_PosY;
	m_Health = p_Health;
	m_Damage = p_Damage;
	m_Side = p_Side;
}

Player::~Player()
{
}