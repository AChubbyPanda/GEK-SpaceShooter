#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"
#include <string>
#include <unordered_map>
#include "LoadTexture.h"
#include "Entity.h"

using namespace HAPISPACE;

struct Positions
{
	float x, y, z;
};

class Texture;
class Entity;

class Visualisation 
{
private:

	BYTE* screenPointer;

	// Screen size
	int screenWidth;
	int screenHeight;
	HAPI_TColour colour;
	Rectangle screenRect;
	std::unordered_map<std::string, Texture*> entityMap;

	void clearToColour(BYTE* screen, HAPI_TColour Col, int width, int height);
	/*void ClearToGray(BYTE grey = 0);*/
	void setPixel(BYTE* ScreenPointer, int x, int y, int width, HAPI_TColour col);

	//void blit(BYTE* screen, int width, int height, int x, int y, Texture* tex);
	void blitzAlpha(BYTE* screen, int width, int height, int x, int y, Texture* tex);
	
public:
	Visualisation();
	~Visualisation();
	bool vizInitialise(int width, int height);
	static void vizShutdown();
	void vizUpdate();
	//std::map< std::string, int > mapLocation;
	bool createSprite(const std::string& name, const std::string& fileName);
	void vizDraw(const std::string name, int x, int y);
};

