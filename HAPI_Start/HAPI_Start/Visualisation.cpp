#include "Visualisation.h"
#include "World.h"
#include "LoadTexture.h"
#include <map>

Visualisation::Visualisation()
	: screenPointer{ nullptr }
	, screenWidth{ 0 }
	, screenHeight{ 0 }
	, screenRect{ 0 , 0 , 0 , 0 }
	, colour{ HAPI_TColour::BLACK }
{
}

Visualisation::~Visualisation()
{
	//Deletes all stored data in the vector, stops memory leaks.
	/*for (size_t i = 0; i != m_VisStorage.size(); i++)
	{
		delete m_VisStorage[i];
	}*/

	for (auto& p : entityMap)
	{
		delete p.second;
	}
}

bool Visualisation::vizInitialise(int width, int height)
{
	if (!HAPI.Initialise(width, height, "Maven, Neil, V8039070"))
	{
		std::cerr << "Could not Initialise " << std::endl;
		return false;
	}

	screenWidth = width;
	screenHeight = height;

	screenRect = Rectangle(0, 0, width, height);

	screenPointer = HAPI.GetScreenPointer();

	HAPI.SetShowFPS(true);

	return true;
}

void Visualisation::vizShutdown()
{
	//delete Instance;
}

void Visualisation::clearToColour(BYTE* screen, HAPI_TColour col, int width, int height)
{
	screenPointer = screen;
	colour = col;
	screenWidth = width;
	screenHeight = height;

	BYTE* Temp{ screen };
	for (int i = 0; i < width * height; i++)
	{
		memcpy(Temp, &col, 4);
		Temp += 4;
	}
}

//void Visualisation::ClearToGray(BYTE grey)
//{
//	memset(m_ScreenPointer, grey, ((int64_t)m_ScreenWidth * (int64_t)m_ScreenHeight) * 4);
//}

void Visualisation::setPixel(BYTE* screen, int x, int y, int width, HAPI_TColour col)
{
	screenPointer = screen;
	screenWidth = width;
	colour = col;
	
	unsigned int OffSet = (x + y * width) * 4;
	memcpy(screenPointer + OffSet, &col, sizeof(col));
}

void Visualisation::vizUpdate()
{
	Visualisation::clearToColour(screenPointer, colour, screenWidth, screenHeight);
}

bool Visualisation::createSprite(const std::string& name, const std::string& fileName)
{
	Texture* tex = Texture::createTexture(name, fileName);

	entityMap[name] = tex;

	return true;
}

void Visualisation::vizDraw(const std::string name, int x, int y)
{  
	for (auto p : entityMap)
	{
		if (p.first == name)
		{
			Texture *tex = p.second;

			blitzAlpha(screenPointer, screenWidth, screenHeight, x, y, tex);
		}
	}
}

//void Visualisation::blit(BYTE* screen, int width, int height, int x, int y, Texture* tex)
//{
//	BYTE* TempPos = screen + (((int64_t)x + (int64_t)y * width)) * 4;
//	BYTE* TempSrc = tex->texturePointer;
//
//	for (int y = 0; y < tex->texHeight; y++)
//	{
//		memcpy(TempPos, TempSrc, (int64_t)tex->texWidth * 4);
//		// Move source pointer to next line
//		TempSrc += (int64_t)tex->texWidth * 4;
//		// Move destination pointer to next line
//		TempPos += (int64_t)height * 4;
//	}
//}

void Visualisation::blitzAlpha(BYTE* screen, int width, int height, int x, int y, Texture* tex)
{
	screenPointer = screen;
	screenWidth = width;
	screenHeight = height;

	int posX(x);
	int posY(y);

	// Passed in the destination (normally the screen) pointer and rectangle and the      
	// source (a texture) pointer and rectangle
	// Also needs the screen position of the top left corner to blit to
	/*Rectangle ScreenBox(0, 0, ScreenWidth, ScreenHeight);
	Rectangle PlayerBox(0, 0, TexWidth, TexHeight);*/
	Rectangle ScreenBox(0, 0, width, height);
	Rectangle PlayerBox(0, 0, tex->texWidth, tex->texHeight);

	//This will adjust the rectangle and cut the image when off screen
	PlayerBox.translate(posX, posY);

	PlayerBox.clipTo(ScreenBox);
	//This adds the image back when it comes back on screen
	PlayerBox.translate(-posX, -posY);

	//inline if statements to check edges of the screen to stop a crash
	posX = posX < 0 ? 0 : posX;
	posY = posY < 0 ? 0 : posY;

	if (PlayerBox.completelyOutside(ScreenBox))
	{
		return;
	}
	BYTE* TempPos = screen + (((int64_t)posX + (int64_t)posY * width)) * 4;
	BYTE* TempSrc = tex->texturePointer + (((int64_t)PlayerBox.left + (int64_t)PlayerBox.top * tex->texWidth)) * 4;

	int EndOfLineDestOffset = (ScreenBox.getWidth() - PlayerBox.getWidth()) * 4;
	int EndOfLineSrcOffset = (tex->texWidth - PlayerBox.getWidth()) * 4;

	for (int y = 0; y < PlayerBox.getHeight(); y++)
	{
		for (int x = 0; x < PlayerBox.getWidth(); x++)
		{
			// remember this needs to contain the texture 
			BYTE blue = TempSrc[0];
			BYTE green = TempSrc[1];
			BYTE red = TempSrc[2];
			BYTE alpha = TempSrc[3];

			if (alpha != 255 && alpha != 0)
			{
				//this needs to contain the background data
				TempPos[0] = TempPos[0] + ((alpha * (blue - TempPos[0])) >> 8);
				TempPos[1] = TempPos[1] + ((alpha * (green - TempPos[1])) >> 8);
				TempPos[2] = TempPos[2] + ((alpha * (red - TempPos[2])) >> 8);
			}
			else if (alpha == 255)
			{
				memcpy(TempPos, TempSrc, 4);
			}

			// Move source pointer to next pixel
			TempSrc += 4;
			// Move destination pointer to next pixel
			TempPos += 4;
		}

		TempPos += EndOfLineDestOffset;
		TempSrc += EndOfLineSrcOffset;
	}
}


