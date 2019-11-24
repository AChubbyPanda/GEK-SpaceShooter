#include "Base.h"

Base::Base()
	: m_PosX{}
	, m_PosY{}
	, m_Health{}
	, m_Damage{}
	, m_Width{}
	, m_Height{}
	, m_Side{}
{
}

Base::~Base()
{
}

bool Base::IsDead()
{
	return true;
}

const void Base::TakeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}
