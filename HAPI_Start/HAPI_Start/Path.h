#pragma once
#include <list>
#include "Vector2.h"

static class Path
{
	 Path* path;
	/* static const int firstPath[22][2];
	 static const int secondPath[22][2];*/

public:
	int start;
	int destination;
	float thereshold;

	Path();
	~Path();
	static int randomPath();
	static Vector2 getPoint(int pathType,int pointIndex);

	static Vector2 lerp(Vector2  from, Vector2  to, float t);
	void update();
};

