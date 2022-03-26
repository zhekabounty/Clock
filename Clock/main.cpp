/*1. Описать часы, у которых есть минутная и часовая стрелка
Операции:
Перевод времени на единицу вперед
Установка текущего времени
Вывод времени
2. Расширить функциональность, добавив секундную стрелку (наследование и агрегация)*/

#include "clock.h"
#include "aclock.h"
#include "inclock.h"
#include <iostream>
using namespace std;

int main() {
	cout << "CLOCK" << endl;
	//
	Clock time;
	cout << "Time: " << time << endl;
	//
	time.next_time();
	cout << "Time after next: " << time << endl;
	//
	time.move_time(14, 45);
	cout << "Time after move: " << time << endl;
	//
	cout << "Time after cin: ";
	cin >> time;
	//
	time.next_time();
	cout << "Time after next: " << time << endl;

	//

	cout << "ACLOCK" << endl;
	//
	AClock new_time(&time);
	cout << "Time: " << new_time << endl;
	//
	new_time.next_time();
	cout << "Time after next: " << new_time << endl;
	//
	new_time.move_time(14, 45, 53);
	cout << "Time after move: " << new_time << endl;
	//
	cout << "Time after cin: ";
	cin >> new_time;
	//
	new_time.next_time();
	cout << "Time after next: " << new_time << endl;

	//

	cout << "INCLOCK" << endl;
	//
	InClock time_new;
	cout << "Time: " << time_new << endl;
	//
	time_new.next_time();
	cout << "Time after next: " << time_new << endl;
	//
	time_new.move_time(14, 45, 53);
	cout << "Time after move: " << time_new << endl;
	//
	cout << "Time after cin: ";
	cin >> time_new;
	//
	time_new.next_time();
	cout << "Time after next: " << time_new << endl;
	return 0;
}