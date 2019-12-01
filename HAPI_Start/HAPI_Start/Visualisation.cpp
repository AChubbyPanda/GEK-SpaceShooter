#include "Visualisation.h"

static Visualisation* Instance = nullptr;

Visualisation::Visualisation()
	: Screen(nullptr)
	, TextureData(nullptr)
	, v_ScreenWidth(720)
	, v_ScreenHeight(720)
{
}

Visualisation::~Visualisation()
{
	//delete Screen;
	delete[] TextureData;

	//Deletes all stored data in the vector, stops memory leaks.
	for (size_t i = 0; i != M_Vis.size(); i++)
	{
		delete M_Vis[i];
	}
}

void Visualisation::Initialise()
{
	if (!Instance)
	{
		Instance = new Visualisation();
		// Check for instance already created
	}

	if (!HAPI.Initialise(Instance->v_ScreenWidth, Instance->v_ScreenHeight, "Maven, Neil, V8039070"))
	{
		return;
	}

	Instance->Screen = HAPI.GetScreenPointer();

	HAPI.SetShowFPS(true);
}

void Visualisation::Shutdown()
{
	delete Instance;
}

Visualisation* Visualisation::Get()
{
	return Instance;
}

void Visualisation::ClearToColour(HAPI_TColour Col)
{
	HAPI_TColour col{ HAPI_TColour::BLACK };

	BYTE* Temp{ Screen };
	for (int i = 0; i < v_ScreenWidth * v_ScreenHeight; i++)
	{
		memcpy(Temp, &Col, 4);
		Temp += 4;
	}
}

void Visualisation::ClearToGray(BYTE grey)
{
	memset(Screen, grey, ((int64_t)v_ScreenWidth * (int64_t)v_ScreenHeight) * 4);
}

void Visualisation::SetPixel(BYTE* Screen, int v_PosX, int v_PosY, int ScreenWidth, HAPI_TColour Col)
{
	unsigned int OffSet = (v_PosX + v_PosY * ScreenWidth) * 4;
	memcpy(Screen + OffSet, &Col, sizeof(Col));
}

unsigned int Visualisation::CreateSprite(const std::string& FileName, const std::string& Name)
{
	Visualisation* NewVisualisation = new Visualisation;

	if (!NewVisualisation->LoadTexture(FileName))
	{
	}

	M_Vis.push_back(NewVisualisation);
	return M_Vis.size() - 1;
}

bool Visualisation::LoadTexture(const std::string& FileName)
{
	if (!HAPI.LoadTexture(FileName, &TextureData, TexWidth, TexHeight))
	{
		// Error - probably the texture could not be found
		HAPI.UserMessage("File Not Found", "Error");
		return false;
	}
	return true;
}

void Visualisation::Draw(unsigned int ID, int PosX, int PosY)
{   //Create an ID for everthing drawn and pushed into the Vector
	M_Vis[ID]->BlitzAlpha(Screen, TexWidth, TexHeight, PosX, PosY);
}

void Visualisation::Blit(BYTE* Screen, int ScreenWidth, int ScreenHeight, int PosX, int PosY)
{
	BYTE* TempPos = Screen + (((int64_t)PosX + (int64_t)PosY * ScreenWidth)) * 4;
	BYTE* TempSrc = TextureData;

	for (int y = 0; y < TexHeight; y++)
	{
		memcpy(TempPos, TempSrc, (int64_t)TexWidth * 4);
		// Move source pointer to next line
		TempSrc += (int64_t)TexWidth * 4;
		// Move destination pointer to next line
		TempPos += (int64_t)ScreenWidth * 4;
	}
}

void Visualisation::BlitzAlpha(BYTE* Position, int ScreenWidth, int ScreenHeight, int PosX, int PosY)
{
	int M_PosX(PosX);
	int M_PosY(PosY);

	// Passed in the destination (normally the screen) pointer and rectangle and the      
	// source (a texture) pointer and rectangle
	// Also needs the screen position of the top left corner to blit to
	Rectangle ScreenBox(0, 0, ScreenWidth, ScreenHeight);
	Rectangle PlayerBox(0, 0, TexWidth, TexHeight);

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
	BYTE* TempPos = Position + (((int64_t)M_PosX + (int64_t)M_PosY * ScreenWidth)) * 4;
	BYTE* TempSrc = TextureData + (((int64_t)PlayerBox.Left + (int64_t)PlayerBox.Top * TexWidth)) * 4;

	int EndOfLineDestOffset = (ScreenBox.Width() - PlayerBox.Width()) * 4;
	int EndOfLineSrcOffset = (TexWidth - PlayerBox.Width()) * 4;

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


