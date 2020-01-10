#include "Player.h"

const void Player::takeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}

//bool Player::IsDead()
//{
//	return true;
//}

const int Player::getScore()
{
	return score;
}

void Player::playerMovement()
{
	const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
	const HAPI_TControllerData& ControlData = HAPI.GetControllerData(0);

	const int leftDeadZoneMax = 8000;
	const int leftDeadZoneMin = -8000;

	//		Controll Input, D-pad and Controll Input, analogue
	if (ControlData.isAttached != false)
	{
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_UP] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > leftDeadZoneMax)
		{
			m_Position.y -= speed;
		}
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_DOWN] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < leftDeadZoneMin)
		{
			m_Position.x -= speed;
		}
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_LEFT] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < leftDeadZoneMin)
		{
			m_Position.y += speed;
		}
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_RIGHT] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > leftDeadZoneMax)
		{
			m_Position.x += speed;
		}
	}

	//	Keyboard Input 
	if (KeyData.scanCode['W'])
	{
		m_Position.y -= speed;
	}
	if (KeyData.scanCode['A'])
	{
		m_Position.x -= speed;

	}
	if (KeyData.scanCode['S'])
	{
		m_Position.y += speed;
	}
	if (KeyData.scanCode['D'])
	{
		m_Position.x += speed;
	}
	if (KeyData.scanCode[HK_SPACE])
	{
		
	}
}

void Player::fireBullet(std::string entityName)
{
	m_EntityName = entityName;
	if (setAlive == false)
	{
		->setAlive = true;

	}

}

void Player::update()
{
	playerMovement();
}

ESide Player::getSide() const
{
	return ESide::eSidePlayer;
}

Player::Player(std::string entityName, int playerHealth, int playerDamage)
	: Entity(entityName)
	, score{ 0 }
	, speed{ 5 }
{
	m_Health = playerHealth;
	m_Damage = playerDamage;
}

Player::~Player()
{
}