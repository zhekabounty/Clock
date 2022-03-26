#include "clock.h"
#include <iostream>
using namespace std;

Clock::Clock(int _hour, int _minute) {
	move_time(_hour, _minute);
}

ostream& operator << (ostream& out, Clock& p) {
	if (p.hour > 9) {
		if (p.minute > 9) {
			out << p.hour << " : " << p.minute;
		}
		else {
			out << p.hour << " : 0" << p.minute;
		}
	}
	else {
		if (p.minute > 9) {
			out << "0" << p.hour << ": " << p.minute;
		}
		else {
			out << "0" << p.hour << " : 0" << p.minute;
		}
	}
	return out;
}

istream& operator >> (istream& in, Clock& p) {
	in >> p.hour >> p.minute;
	return in;
}

void Clock::next_time() {
	minute++;
	if (minute >= 60) {
		minute %= 60;
		hour++;
	}
	if (hour >= 24) {
		hour %= 24;
	}
}

void Clock::move_time(int _hour, int _minute) {
	hour = _hour;
	minute = _minute;
}

int& Clock::getHour() {
	return hour;
}
int& Clock::getMinute() {
	return minute;
}