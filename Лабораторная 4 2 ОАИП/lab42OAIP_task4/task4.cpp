#include <iostream>
using namespace std;
void input(int size); // Ввод данных
void output();        // Вывод данных
void find(char lastName[]); // Поиск данных

// Структура для хранения информации о студентах
typedef struct Students
{
	char fio[16]; 
	char group[3]; 
} STUD;

int number;          // Количество студентов
FILE* f;             // Указатель на файл
errno_t err;         // Код ошибки

int main()
{
	setlocale(LC_ALL, "Russian"); 
	int choice;                   // Выбор действия
	char fio[16];              

	// Главное меню
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по фамилии\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;

		// Обработка выбора пользователя
		switch (choice)
		{
		case 1: // Ввод данных
			cout << "Введите количество студентов: ";
			cin >> number;
			input(number);
			break;

		case 2: // Вывод данных из файла
			output();
			break;

		case 3: // Поиск по фамилии
			cout << "Введите фамилию: ";
			cin >> fio;
			find(fio);
			break;

		case 0: // Выход из программы
			exit(0);
			break;
		}
	} while (choice != 0); // Цикл выполняется, пока не выбрано 0
}

// Функция ввода данных
void input(int size)
{
	STUD buf = { ' ', ' ' }; // Буфер для записи данных
	if (!fopen_s(&f, "base.bin", "ab")) // Открытие файла для добавления
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Фамилия: ";
			cin >> buf.fio;     // Ввод фамилии
			cout << "Группа: ";
			cin >> buf.group;   // Ввод группы
			fwrite(&buf, sizeof(buf), 1, f); // Запись данных в файл
		}
		fclose(f); // Закрытие файла
	}
	else {
		cout << "Ошибка открытия файла"; 
		return;
	}
}

// Функция вывода данных из файла
void output()
{
	STUD buf; // Буфер для чтения данных
	if (!fopen_s(&f, "base.bin", "rb")) // Открытие файла для чтения
	{
		cout << "\nФамилия    Группа\n";
		fread(&buf, sizeof(buf), 1, f); // Чтение первой записи
		while (!feof(f)) // Пока не конец файла
		{
			cout << buf.fio << "\t    " << buf.group << endl; // Вывод данных
			fread(&buf, sizeof(buf), 1, f); // Чтение следующей записи
		}
		cout << endl;
		fclose(f); // Закрытие файла
	}
	else
	{
		cout << "Ошибка открытия файла"; // Обработка ошибки
		return;
	}
}

// Функция поиска по фамилии
void find(char lastName[16])
{
	bool flag = false;  // Флаг для проверки нахождения записи
	STUD buf;           // Буфер для чтения данных
	if (!fopen_s(&f, "base.bin", "rb")) // Открытие файла для чтения
	{
		while (!feof(f)) // Пока не конец файла
		{
			fread(&buf, sizeof(buf), 1, f); // Чтение записи
			if (strcmp(lastName, buf.fio) == 0) // Сравнение фамилии
			{
				cout << "\nФамилия    Группа\n";
				cout << buf.fio << "\t    " << buf.group << endl; // Вывод найденной записи
				flag = true;
				break;
			}
		}
		fclose(f); // Закрытие файла
		if (!flag)
			cout << "Ничего не найдено\n"; 
	}
	else
	{
		cout << "Ошибка открытия файла"; 
		return;
	}
}
