#pragma once
class TimeClass
{
	int oldTime;
	int newTime;

	TimeClass();
	~TimeClass();

public:
	static TimeClass timeClass;
	void delta(int oldT, int newT);
};

