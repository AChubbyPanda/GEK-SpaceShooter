#include "Path.h"

Path::Path()
	: firstPath{ {1536,720}, {1536,650}, {1466,650}, {1466, 580}, {1396, 580}, {1396,510}, {1326, 510}, {1326,440}, {1256, 440}, {1256, 370},
	{1186,370}, {1186, 300}, { 1116, 300}, {1116, 230}, {1046, 230}, {1046, 160} , {976, 160}, {976, 90}, {906, 90}, {906, 20}, {836, 20}, 
	{836, -50} }
	, secondPath{ {900,0}, {900, 70}, {970, 70}, { 970, 140}, {1040, 140}, {1040, 210}, {1110, 210}, {1110, 280}, {1040, 280}, {1040, 350}, {970, 350}, {970, 420},
	{900, 420}, {900, 510}, {970, 510}, {970, 580}, {1040, 580}, {1040, 650}, {1110, 650}, {1110, 720}, {1040,720}, {1040, 790}}
{
}

Path::~Path()
{
}

void Path::randomPath()
{
	int result = rand() % 2;

	if (result == 1)
	{
		firstPath;
	}
	if (result == 2)
	{
		secondPath;
	}
}