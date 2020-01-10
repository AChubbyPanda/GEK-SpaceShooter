#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;

class Rectangle
{
private:
	BYTE* rectangleData;
	int width;
	int height;
public:
	int left{ 0 }, right{ 0 }, top{ 0 }, bottom{ 0 };
	int getWidth() const { return right - left; };
	int getHeight() const { return bottom - top; };

	bool completelyOutside(const Rectangle& Other) const;
	void clipTo(const Rectangle& Other);
	void translate(int DX, int DY);
	Rectangle(int L, int T, int R, int B);
	~Rectangle();
};
