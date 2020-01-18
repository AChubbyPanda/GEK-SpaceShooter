#pragma once
#include <list>
#include "Vector2.h"
#include <time.h>

class Path
{
	static Path* path;
	/*static const int firstPath[22][2]; /*= { {1080,720}, {1080,650}, {1010,650}, {1010, 580}, {940, 580}, {940,510}, {870, 510}, {870,440}, {800, 440}, {800, 370},
	{710,370}, {710, 300}, { 640, 300}, {640, 230}, {570, 230}, {570, 160} , {500, 160}, {500, 90}, {430, 90}, {430, 20}, {360, 20},
	{360, -50} };*/
	static const int secondPath[22][2]; /*= { {900,0}, {900, 70}, {970, 70}, { 970, 140}, {1040, 140}, {1040, 210}, {1110, 210}, {1110, 280}, {1040, 280}, {1040, 350}, {970, 350}, {970, 420},
	{900, 420}, {900, 510}, {970, 510}, {970, 580}, {1040, 580}, {1040, 650}, {1110, 650}, {1110, 720}, {1040,720}, {1040, 790} };*/

public:
	int start;
	int destination;
	float thereshold;

	Path();
	~Path();
	static int randomPath();
	static Vector2 getPoint(int pathType,int pointIndex);
	static Path* getInstance();
	static Vector2 lerp(Vector2  from, Vector2  to, float t);
	void update();
};

