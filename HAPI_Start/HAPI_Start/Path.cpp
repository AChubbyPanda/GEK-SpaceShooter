#include "Path.h"
#include <cmath>
#include <HAPI_lib.h>

Path* Path::path = NULL;

const int Path::firstPath { {1080,720}, {1080,650}, {1010,650}, {1010, 580}, {940, 580}, {940,510}, {870, 510}, {870,440}, {800, 440}, {800, 370},
	{710,370}, {710, 300}, { 640, 300}, {640, 230}, {570, 230}, {570, 160} , {500, 160}, {500, 90}, {430, 90}, {430, 20}, {360, 20},
	{360, -50} };

Path::Path()
	/*: firstPath{ {1080,720}, {1080,650}, {1010,650}, {1010, 580}, {940, 580}, {940,510}, {870, 510}, {870,440}, {800, 440}, {800, 370},
	{710,370}, {710, 300}, { 640, 300}, {640, 230}, {570, 230}, {570, 160} , {500, 160}, {500, 90}, {430, 90}, {430, 20}, {360, 20},
	{360, -50} }
	, secondPath{ {900,0}, {900, 70}, {970, 70}, { 970, 140}, {1040, 140}, {1040, 210}, {1110, 210}, {1110, 280}, {1040, 280}, {1040, 350}, {970, 350}, {970, 420},
	{900, 420}, {900, 510}, {970, 510}, {970, 580}, {1040, 580}, {1040, 650}, {1110, 650}, {1110, 720}, {1040,720}, {1040, 790}}*/
	: start{ 0 }
	, destination{ 0 }
	, thereshold{ 0.1f }
{
}

Path::~Path()
{
}

int Path::randomPath()
{
	int result = rand() % 2;

	return result;
}

Vector2 Path::getPoint(int pathType, int pointIndex)
{
	if (pathType == 1)
	{
		return Vector2(firstPath[pointIndex][0], firstPath[pointIndex][1]);
	}
	else
	{
		return Vector2(secondPath[pointIndex][0], firstPath[pointIndex][1]);
	}
}

Path* Path::getInstance()
{
	if (path == NULL)
	{
		path = new Path();
	}
	return path;
}


Vector2 Path::lerp(Vector2 from, Vector2 to, float t)
{
	float posX = (from.x + t * (to.x - from.x));
	float posY = (from.y + t * (to.y - from.y));

	return Vector2(posX, posY);
}


void Path::update()
{	
}