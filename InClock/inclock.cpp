#include "inclock.h"

void InClock::next_time() {
	second++;
	if (second >= 60) {
		second %= 60;
		Clock::next_time();
	}
}

void InClock::move_time(int _hour, int _minute, int _second) {
	Clock::move_time(_hour, _minute);
	second = _second;
}

ostream& operator << (ostream& out, InClock& p) {
	if (p.getHour() > 9) {
		if (p.getMinute() > 9) {
			if (p.second > 9) {
				out << p.getHour() << " : " << p.getMinute() << " : " << p.second;
			}
			else {
				out << p.getHour() << " : " << p.getMinute() << " : 0" << p.second;
			}
		}
		else {
			if (p.second > 9) {
				out << p.getHour() << " : 0" << p.getMinute() << " : " << p.second;
			}
			else {
				out << p.getHour() << " : 0" << p.getMinute() << " : 0" << p.second;
			}
		}
	}
	else {
		if (p.getMinute() > 9) {
			if (p.second > 9) {
				out << "0" << p.getHour() << " : " << p.getMinute() << " : " << p.second;
			}
			else {
				out << "0" << p.getHour() << " : " << p.getMinute() << " : 0" << p.second;
			}
		}
		else {
			if (p.second > 9) {
				out << "0" << p.getHour() << " : 0" << p.getMinute() << " : " << p.second;
			}
			else {
				out << "0" << p.getHour() << " : 0" << p.getMinute() << " : 0" << p.second;
			}
		}
	}
	return out;
}

istream& operator >> (istream& in, InClock& p) {
	in >> p.getHour() >> p.getMinute() >> p.second;
	return in;
}