#pragma once
#include "clock.h"

class InClock :public Clock {
	int second;
public:
	InClock(int _hour = 0, int _minute = 0, int _second = 0) : Clock(_hour, _minute), second(_second) {};
	void move_time(int _hour, int _minute, int _second);
	void next_time();
	friend ostream& operator << (ostream& out, InClock& p);
	friend istream& operator >> (istream& in, InClock& p);
};