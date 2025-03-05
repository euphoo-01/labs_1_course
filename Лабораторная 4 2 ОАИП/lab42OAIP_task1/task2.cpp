#include <conio.h>
#include <iostream>
using namespace std;
#define DELAY 900
void update(struct MyTime* t);
void display(struct MyTime* t);

struct MyTime
{
	int hours;
	int minutes;
	int seconds;
};

int main(void)
{
	struct MyTime St;
	St.hours = 0;
	St.minutes = 0;
	St.seconds = 0;
	for (; ;)
	{
		update(&St);
		display(&St);
		if (_kbhit())
			return 0;
	}
}

void update(struct MyTime* t)
{
	t->seconds++;
	if (t->seconds == 60) { t->seconds = 0; t->minutes++; }
	if (t->minutes == 60) { t->minutes = 0; t->hours++; }
	if (t->hours == 24)
		t->hours = 0;
	for (long int i = 1; i < DELAY; ++i);
}

void display(struct MyTime* t)
{
	cout << t->hours << '.' << t->minutes << '.' << t->seconds << endl;
}
