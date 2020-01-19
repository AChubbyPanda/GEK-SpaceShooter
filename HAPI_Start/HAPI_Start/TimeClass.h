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
	int getDelta();
	static TimeClass* getInstance();
	void update();
};

