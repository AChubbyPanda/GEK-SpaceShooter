#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;

class Rectangle
{
private:
	BYTE* RectangleData;
	
public:
	int Left{ 0 }, Right{ 0 }, Top{ 0 }, Bottom{ 0 };
	int Width() const { return Right - Left; };
	int Height() const { return Bottom - Top; };

	bool CompletelyOutside(const Rectangle& Other) const;
	void ClipTo(const Rectangle& Other);
	void Translate(int DX, int DY);
	Rectangle(int L, int T, int R, int B);
	~Rectangle();
};
