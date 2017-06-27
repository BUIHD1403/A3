#pragma once
#include <iostream>
using namespace std;

class Event
{
private:
	char Type;
	int Time;
	int Length;

public:
	Event();
	void setType(const char aType);
	void setTime(const int aTime);
	void setLength(const int aLength);
	char getType();
	int getTime();
	int getLength();
	bool operator==(const Event &rhs);
	bool operator>(const Event &rhs);
	friend ostream & operator<<(ostream & os, const Event& anEvent);
};