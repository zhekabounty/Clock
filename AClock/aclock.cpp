#include "aclock.h"

AClock::AClock(int _hour, int _minute, int _second) {
	move_time(_hour, _minute, _second);
}

void AClock::next_time() {
	second++;
	if (second >= 60) {
		second %= 60;
		time->next_time();
	}
}

void AClock::move_time(int _hour, int _minute, int _second) {
	time->move_time(_hour, _minute);
	second = _second;
}

ostream& operator << (ostream& out, AClock& p) {
	if (p.time->getHour() > 9) {
		if (p.time->getMinute() > 9) {
			if (p.second > 9) {
				out << p.time->getHour() << " : " << p.time->getMinute() << " : " << p.second;
			}
			else {
				out << p.time->getHour() << " : " << p.time->getMinute() << " : 0" << p.second;
			}
		}
		else {
			if (p.second > 9) {
				out << p.time->getHour() << " : 0" << p.time->getMinute() << " : " << p.second;
			}
			else {
				out << p.time->getHour() << " : 0" << p.time->getMinute() << " : 0" << p.second;
			}
		}
	}
	else {
		if (p.time->getMinute() > 9) {
			if (p.second > 9) {
				out << "0" << p.time->getHour() << " : " << p.time->getMinute() << " : " << p.second;
			}
			else {
				out << "0" << p.time->getHour() << " : " << p.time->getMinute() << " : 0" << p.second;
			}
		}
		else {
			if (p.second > 9) {
				out << "0" << p.time->getHour() << " : 0" << p.time->getMinute() << " : " << p.second;
			}
			else {
				out << "0" << p.time->getHour() << " : 0" << p.time->getMinute() << " : 0" << p.second;
			}
		}
	}
	return out;
}

istream& operator >> (istream& in, AClock& p) {
	in >> p.time->getHour() >> p.time->getMinute() >> p.second;
	return in;
}