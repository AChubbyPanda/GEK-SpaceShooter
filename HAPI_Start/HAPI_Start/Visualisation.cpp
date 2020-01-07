#include "Visualisation.h"
#include "World.h"
#include "LoadTexture.h"
#include <map>

Visualisation::Visualisation()
	: m_ScreenPointer{ nullptr }
	, m_ScreenWidth{ 0 }
	, m_ScreenHeight{ 0 }
	, m_ScreenRect{ 0 , 0 , 0 , 0 }
{
}

Visualisation::~Visualisation()
{
	//Deletes all stored data in the vector, stops memory leaks.
	/*for (size_t i = 0; i != m_VisStorage.size(); i++)
	{
		delete m_VisStorage[i];
	}*/

	for (auto& p : m_EntityMap)
	{
		delete p.second;
	}
}

bool Visualisation::Initialise(int screenWidth, int screenHeight)
{
	if (!HAPI.Initialise(screenWidth, screenHeight, "Maven, Neil, V8039070"))
	{
		std::cerr << "Could not Initialise " << std::endl;
		return false;
	}

	m_ScreenWidth = screenHeight;
	m_ScreenHeight = screenHeight;

	m_ScreenRect = Rectangle(0, 0, screenWidth, screenHeight);

	m_ScreenPointer = HAPI.GetScreenPointer();

	HAPI.SetShowFPS(true);

	return true;
}

void Visualisation::Shutdown()
{
	//delete Instance;
}

void Visualisation::ClearToColour(HAPI_TColour Col)
{
	HAPI_TColour col{ HAPI_TColour::BLACK };

	BYTE* Temp{ m_ScreenPointer };
	for (int i = 0; i < m_ScreenWidth * m_ScreenHeight; i++)
	{
		memcpy(Temp, &Col, 4);
		Temp += 4;
	}
}

void Visualisation::ClearToGray(BYTE grey)
{
	memset(m_ScreenPointer, grey, ((int64_t)m_ScreenWidth * (int64_t)m_ScreenHeight) * 4);
}

void Visualisation::SetPixel(BYTE* Screen, int v_PosX, int v_PosY, int ScreenWidth, HAPI_TColour Col)
{
	unsigned int OffSet = (v_PosX + v_PosY * ScreenWidth) * 4;
	memcpy(Screen + OffSet, &Col, sizeof(Col));
}

bool Visualisation::CreateSprite(const std::string& Name, const std::string& FileName)
{
	LoadTexture* tex = LoadTexture::CreateTexture(Name, FileName);

	m_EntityMap[Name] = tex;

	return true;
}

void Visualisation::Draw(const std::string Name, int PosX, int PosY)
{  
	for (auto p : m_EntityMap)
	{
		if (p.first == Name)
		{
			LoadTexture *tex = p.second;

			BlitzAlpha(m_ScreenPointer, m_ScreenWidth, m_ScreenHeight, PosX, PosY, tex->m_TexturePointer);
		}
	}
}

void Visualisation::Blit(BYTE* Screen, int m_ScreenWidth, int m_ScreenHeight, int PosX, int PosY, BYTE* TexturePointer)
{
	BYTE* TempPos = Screen + (((int64_t)PosX + (int64_t)PosY * m_ScreenWidth)) * 4;
	BYTE* TempSrc = TexturePointer;

	for (int y = 0; y < m_TexHeight; y++)
	{
		memcpy(TempPos, TempSrc, (int64_t)m_TexWidth * 4);
		// Move source pointer to next line
		TempSrc += (int64_t)m_TexWidth * 4;
		// Move destination pointer to next line
		TempPos += (int64_t)m_ScreenHeight * 4;
	}
}

void Visualisation::BlitzAlpha(BYTE* Position, int m_ScreenWidth, int m_ScreenHeight, int PosX, int PosY, BYTE* TexturePointer)
{
	int M_PosX(PosX);
	int M_PosY(PosY);

	// Passed in the destination (normally the screen) pointer and rectangle and the      
	// source (a texture) pointer and rectangle
	// Also needs the screen position of the top left corner to blit to
	/*Rectangle ScreenBox(0, 0, ScreenWidth, ScreenHeight);
	Rectangle PlayerBox(0, 0, TexWidth, TexHeight);*/
	Rectangle ScreenBox(M_PosX, M_PosY, m_ScreenWidth, m_ScreenHeight);
	Rectangle PlayerBox(M_PosY, M_PosY, m_TexWidth, m_TexHeight);

	//This will adjust the rectangle and cut the image when off screen
	PlayerBox.Translate(PosX, PosY);

	PlayerBox.ClipTo(ScreenBox);
	//This adds the image back when it comes back on screen
	PlayerBox.Translate(-PosX, -PosY);

	//inline if statements to check edges of the screen to stop a crash
	M_PosX = M_PosX < 0 ? 0 : M_PosX;
	M_PosY = M_PosY < 0 ? 0 : M_PosY;

	if (PlayerBox.CompletelyOutside(ScreenBox))
	{
		return;
	}
	BYTE* TempPos = Position + (((int64_t)M_PosX + (int64_t)M_PosY * m_ScreenWidth)) * 4;
	BYTE* TempSrc = TexturePointer + (((int64_t)PlayerBox.Left + (int64_t)PlayerBox.Top * m_TexWidth)) * 4;

	int EndOfLineDestOffset = (ScreenBox.Width() - PlayerBox.Width()) * 4;
	int EndOfLineSrcOffset = (m_TexWidth - PlayerBox.Width()) * 4;

	for (int y = 0; y < PlayerBox.Height(); y++)
	{
		for (int x = 0; x < PlayerBox.Width(); x++)
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


