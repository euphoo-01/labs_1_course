#include <iostream>

#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name;
	int dela;
	cout << "Привет, как тебя зовут?" << endl;
	cin >> name;
	cout << "Как у тебя дела, " << name << "? (1 - Хорошо, 2 - Нормально, 3 - Плохо, 4 - Почти хорошо" << endl;
	cin >> dela;
	switch (dela) {
	case 1:
		cout << "У меня тоже хорошо! Ну, я пойду, " << name << ". Пока!"; break;
	case 2:
		cout << "А должно быть хорошо! Удачи, " << name << "!"; break;
	case 3:
		cout << "Чего так? " << endl;
		cin >> dela;
		cout << "Ясно. Пока, " << name << "."; break;
	case 4:
		cout << "Нельзя быть почти беременным, " << name << ". Пока!"; break;
	default:
		cout << "Не понимаю тебя, " << name << "!";
		break;
	}
	return 0;
}