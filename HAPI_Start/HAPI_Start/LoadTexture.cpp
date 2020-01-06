#include "LoadTexture.h"

bool LoadTexture::Load(const std::string& FileName)
{
	if (!HAPI.LoadTexture(FileName, &m_TexturePointer, m_TexWidth, m_TexHeight))
	{
		HAPI.UserMessage("ERROR ", "Texture Failed to load ");
		return false;
	}
	return true;
}

LoadTexture* LoadTexture::CreateTexture(const std::string& Name, const std::string& FileName)
{
	LoadTexture* tex = new LoadTexture();

	if (!tex->Load(FileName))
	{
		delete tex;
		return false;
	};

	return tex;
}