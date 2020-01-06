#include "BackGround.h"

BackGround::BackGround(std::string EntityName)
	: Entity(EntityName)
{
}

BackGround::~BackGround()
{
}

const void BackGround::TakeDamage()
{
}

void BackGround::Update()
{
}

ESide BackGround::GetSide() const
{
	return ESide::eSideNeutral;
}