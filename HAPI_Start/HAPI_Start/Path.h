#pragma once
#include <list>
#include "Vector2.h"
#include <time.h>

class Path
{
	static Path* path;
	int firstPath [22][2];
	int secondPath[22][2];

public:
	int start;
	int destination;
	float thereshold;

	Path();
	~Path();
	int randomPath();
	Vector2 getPoint(int pathType,int pointIndex);
	static Path* getInstance();
	static Vector2 lerp(Vector2  from, Vector2  to, float t);
	void update();
};

