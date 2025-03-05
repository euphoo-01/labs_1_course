#include <iostream>
using namespace std;

struct Worker
{
	char lastName[30];
	char name[30];
	char position[30];
	int year;
	int age;

};

int main()
{
	setlocale(LC_ALL, "Russian");
	const int size = 3;
	const int currentYear = 2025;
	int i, b, counter = 0;
	Worker a[size];
	for (i = 0; i < size; i++)
	{
		cout << "Введите фамилию " << i + 1 << "-ого работника " << endl;
		cin >> a[i].lastName;
		cout << "Введите имя " << i + 1 << "-ого работника " << endl;
		cin >> a[i].name;
		cout << endl << "Должность: ";
		cin >> a[i].position;
		cout << endl << "Год поступления на работу: ";
		cin >> a[i].year;
		cout << endl << "Возраст: ";
		cin >> a[i].age;
	}
	cout << endl << "Список сотрудников: ";

	for (int i = 0; i < size; i++) {
		cout << endl << a[i].lastName << " " << a[i].name <<
			" " << a[i].position << " " << a[i].age << " y.o";
	}

	cout << endl << "Введите стаж работы ";
	cin >> b;
	cout << endl;
	for (i = 0; i < size; i++)
	{
		if (b < currentYear - a[i].year)
		{
			cout << a[i].lastName << " ";
			counter++;
		}
		else
			if (i == size - 1 && counter > 0)
				cout << "Работников с более высоким стажем нет.";
	}
	return 0;
}
