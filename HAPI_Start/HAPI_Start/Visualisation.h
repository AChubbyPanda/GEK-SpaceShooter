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

class LoadTexture;
class Entity;

class Visualisation : public LoadTexture 
{
private:

	BYTE* screenPointer;

	// Screen size
	int screenWidth;
	int screenHeight;
	HAPI_TColour colour;
	Rectangle screenRect;
	std::unordered_map<std::string, LoadTexture*> entityMap;

	void clearToColour(BYTE* screen, HAPI_TColour Col, int width, int height);
	/*void ClearToGray(BYTE grey = 0);*/
	void setPixel(BYTE* ScreenPointer, int x, int y, int width, HAPI_TColour col);

	//bool LoadTexture(const std::string& FileName, BYTE* TexturePointer);

	void blit(BYTE* screen, int width, int height, int x, int y, BYTE* texturePointer);
	void blitzAlpha(BYTE* screen, int width, int height, int x, int y, BYTE* texturePointer);
	
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

