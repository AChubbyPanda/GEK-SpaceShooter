#include "Rectangle.h"
#include <algorithm>

//static Rectangle* Instance = nullptr;

Rectangle::Rectangle(int l, int t, int r, int b)
	:rectangleData(nullptr)
	, width{ 0 }
	, height{ 0 }
{
	left = l;
	right = r;
	top = t;
	bottom = b;
}

Rectangle::~Rectangle()
{
	delete rectangleData;
}

bool Rectangle::completelyOutside(const Rectangle& other) const
{
	if (other.right < left)
		return true;

	if (other.top > bottom)
		return true;

	if (other.left > right)
		return true;

	if (other.bottom < top)
		return true;

	return false;
}

void Rectangle::clipTo(const Rectangle& other)
{
	left = std::max(left, other.left);
	right = std::min(right, other.right);
	top = std::max(top, other.top);
	bottom = std::min(bottom, other.bottom);
}

void Rectangle::translate(int dX, int dY)
{
	left += dX;
	right += dX;
	top += dY;
	bottom += dY;
}