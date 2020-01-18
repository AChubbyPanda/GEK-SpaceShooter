#pragma once
class TimeClass
{
private:
	static TimeClass* timeClass;

	int oldTime;
	int newTime;

	TimeClass();
	~TimeClass();

public:
	void delta(int oldT, int newT);
	static TimeClass* getInstance();
};

