#include "Rectangle.h"
#include <algorithm>

static Rectangle* Instance = nullptr;

Rectangle::Rectangle(int L, int T, int R, int B)
	:RectangleData(nullptr)
{
	Left = L;
	Right = R;
	Top = T;
	Bottom = B;
}

Rectangle::~Rectangle()
{
	delete RectangleData;
}

bool Rectangle::CompletelyOutside(const Rectangle& Other) const
{
	if (Other.Right < Left)
		return true;

	if (Other.Top > Bottom)
		return true;

	if (Other.Left > Right)
		return true;

	if (Other.Bottom < Top)
		return true;

	return false;
}

bool Rectangle::CompletelyInside(const Rectangle& Other) const
{
	if (Left < Other.Left)
		return false;

	if (Right < Other.Right)
		return false;

	if (Top < Other.Top)
		return false;

	if (Bottom < Other.Bottom)
		return false;

	return true;
}

void Rectangle::ClipTo(const Rectangle& Other)
{
	Left = std::max(Left, Other.Left);
	Right = std::min(Right, Other.Right);
	Top = std::max(Top, Other.Top);
	Bottom = std::min(Bottom, Other.Bottom);
}

void Rectangle::Translate(int DX, int DY)
{
	Left += DX;
	Right += DX;
	Top += DY;
	Bottom += DY;
}