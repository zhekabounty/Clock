#pragma once
#include "clock.h"

class AClock {
	Clock* time;
	int second;
public:
	AClock(Clock* _time) : time(_time), second(0) {};
	AClock(int _hour = 0, int _minute = 0, int _second = 0);
	void move_time(int _hour, int _minute, int _second);
	void next_time();
	friend ostream& operator << (ostream& out, AClock& p);
	friend istream& operator >> (istream& in, AClock& p);
};