#include <iostream>

#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name;
	int dela;
	cout << "������, ��� ���� �����?" << endl;
	cin >> name;
	cout << "��� � ���� ����, " << name << "? (1 - ������, 2 - ���������, 3 - �����, 4 - ����� ������" << endl;
	cin >> dela;
	switch (dela) {
	case 1:
		cout << "� ���� ���� ������! ��, � �����, " << name << ". ����!"; break;
	case 2:
		cout << "� ������ ���� ������! �����, " << name << "!"; break;
	case 3:
		cout << "���� ���? " << endl;
		cin >> dela;
		cout << "����. ����, " << name << "."; break;
	case 4:
		cout << "������ ���� ����� ����������, " << name << ". ����!"; break;
	default:
		cout << "�� ������� ����, " << name << "!";
		break;
	}
	return 0;
}