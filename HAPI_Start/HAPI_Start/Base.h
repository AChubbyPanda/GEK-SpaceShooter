#pragma once
#include <string>

enum ESide 
{
	eSidePlayer,
	eSideEnemy,
	SideNeutral
};

class Base
{
private:
	

public:
	virtual bool IsDead() = 0;
	const virtual void TakeDamage() = 0;

	Base();
	~Base();

protected:
	int m_PosX;
	int m_PosY;

	unsigned int m_Health;
	unsigned int m_Damage;
	unsigned int m_Width;
	unsigned int m_Height;

	ESide m_Side;

	std::string m_Name;
};

