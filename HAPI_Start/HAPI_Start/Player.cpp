#include "Player.h"
#include "Bullet.h"

const void Player::takeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
	
	if (m_Health <= 0)
	{
		setDead();
		lifes - 1;
		if (lifes <= 0)
		{
			//Game Over
		}
		else
		{
			m_Health = respawnHealth;
			setAlive();
		}
	}
}

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
		if (ControlData.digitalButtons[HK_ANALOGUE_RIGHT_TRIGGER])
		{
			fireBullet(getPositionX(), getPositionY());
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
		fireBullet(getPositionX(), getPositionY());
	}
}

void Player::fireBullet(int x, int y)
 {
	x = getPositionX()+75;
	y = getPositionY()+50;
	Bullet* bullet = (Bullet*)World::getInstance()->getEntity((int)ESprites::ESpritesPlayerLaser);
	bullet->setPosition(Vector2(x, y));
}

int Player::getPositionX()
{
	return (int)m_Position.x;
}

int Player::getPositionY()
{
	return (int)m_Position.y;
}


void Player::update()
{
	playerMovement();
}

int Player::getSide() const
{
	return (int)ESide::eSidePlayer;
}

Player::Player(std::string entityName, int playerHealth, int playerDamage)
	: Entity(entityName)
	, score{ 0 }
	, speed{ 5 }
	, lifes{ 3 }
	, respawnHealth{ 20 }
{
	m_Health = playerHealth;
	m_Damage = playerDamage;
}

Player::~Player()
{
}