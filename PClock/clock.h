#pragma once

#include <ostream>
#include <istream>
using namespace std;

class Clock {
	int hour, minute;
public:
	Clock(int _hour = 0, int _minute = 0);
	virtual void next_time();
	void move_time(int _hour, int _minute);
	int& getHour();
	int& getMinute();
	friend ostream& operator << (ostream& out, Clock& p);
	friend istream& operator >> (istream& in, Clock& p);
};