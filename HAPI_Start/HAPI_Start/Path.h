#pragma once
#include <list>
#include "Vector2.h"

class Path
{
	int firstPath [22][2];
	int secondPath[22][2];

public:
	Path();
	~Path();
	void randomPath();
};

