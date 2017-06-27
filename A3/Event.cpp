#include "Event.h"
#include <iostream>

Event::Event()
{
	Type = 'A';
	Time = 0;
	Length = 0;
}

void Event::setType(const char aType)
{
	Type = aType;
	return;
}

void Event::setLength(const int aLength)
{
	Length = aLength;
	return;
}

void Event::setTime(const int aTime)
{
	Time = aTime;
	return;
}

int Event::getLength()
{
	return Length;
}

int Event::getTime()
{
	return Time;
}

char Event::getType()
{
	return Type;
}

bool Event::operator==(const Event &rhs)
{
	if (getType() == rhs.Type && getTime()== rhs.Time)
	{
		return true;
	}
	else
		return false;
}

bool Event::operator>(const Event &rhs)
{
	if (this->getTime() > rhs.Time)
	{
		if (this->getType > rhs.Type || this->getType == rhs.Type)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
 }

ostream & operator<<(ostream & os, const Event & anEvent)
{
	os << "Type of Event: " <<  anEvent.Type << endl;
	os << "Time of Event: " << anEvent.Time << endl;
	if (anEvent.Type == 'A')
	{
		os << "Length of Event: " << anEvent.Length << endl;
	}
	return;
	// TODO: insert return statement here
}

