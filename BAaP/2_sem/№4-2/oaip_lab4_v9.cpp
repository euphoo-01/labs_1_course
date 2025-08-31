#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <locale>
#include <iomanip> // для округления среднего балла

using namespace std;

typedef struct Students
{
    string firstName;
    string lastName;
    string patronymic;
    string dateOfEntering;
    string spec;
    int group;
    string faculty;
    float averageMarks;
} STU;

vector<STU> students;
vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string dictionary = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ-";
vector<string> faculties = {"ФИТ", "ХТИТ", "ЛХФ", "ТОВ", "ПИМ", "ИЭФ", "ФЗО"};

void input(int);
void output(int);
void del();
void find();
void writeToFile();
void readFromFile();
void exit(int *);
vector<int> splitData(string date);
bool isValidName(const string &name);
bool isValidPatronymic(const string &name);
bool isValidDate(const string &date);
bool isValidFaculty(const string &faculty);
bool isValidGroup(int group);
bool isValidAverageMarks(float marks);
bool isValidHyphen(const string &name);

bool isCorrectChoice(string &choice);

int main()
{
    SetConsoleOutputCP(1251); // Установка кодировки консоли для вывода
    SetConsoleCP(1251);       // Установка кодировки консоли для ввода
    setlocale(LC_ALL, "Russian");

    int choice = -1;
    string choice_str;
    do
    {
        cout << "Меню управления: \n 0) Выход из программы \n 1) Ввести данные студента \n 2) Вывести данные студента \n 3) Удалить данные о студенте \n 4) Найти студента \n 5) Сохранить информацию в файл \n 6) Прочитать информацию из файла \nВаш выбор: ";
        getline(cin, choice_str);
        if (isCorrectChoice(choice_str))
        {
            choice = stoi(choice_str);
            switch (choice)
            {
            case 1:
            {
            exc_start:
                cout << "Сколько человек вы хотите добавить? ";
                string count_str;
                try
                {
                    while (!(getline(cin, count_str)) || stoi(count_str) <= 0 || !all_of(count_str.begin(), count_str.end(), ::isdigit))
                    {
                        cout << "Ошибка! Введите корректное количество студентов: ";
                    }
                    input(stoi(count_str));
                }
                catch (exception &e)
                {
                    cerr << "Ошибка! " << endl;
                    goto exc_start;
                }

                break;
            }
            case 2:
                output(choice);
                break;
            case 3:
                del();
                break;
            case 4:
                find();
                break;
            case 5:
                writeToFile();
                break;
            case 6:
                readFromFile();
                break;
            case 0:
                break;
            default:
                cout << "Ошибка! Такого варианта нет." << endl;
                break;
            }
        }
        else
        {
            cerr << "Введите корректный выбор!" << endl;
        }
    } while (choice != 0);
    return 0;
}

void input(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Введите данные студента: " << endl;
        STU student;

        // Ввод имени
        while (true)
        {
            cout << "Введите имя: ";
            getline(cin, student.firstName);
            if (isValidName(student.firstName) && isValidHyphen(student.firstName))
            {
                break;
            }
            cout << "Ошибка! Неверное имя. Попробуйте снова." << endl;
        }

        // Ввод фамилии
        while (true)
        {
            cout << "Введите фамилию: ";
            getline(cin, student.lastName);
            if (isValidName(student.lastName) && isValidHyphen(student.lastName))
            {
                break;
            }
            cout << "Ошибка! Неверная фамилия. Попробуйте снова." << endl;
        }

        // Ввод отчества
        while (true)
        {
            cout << "Введите отчество: ";
            getline(cin, student.patronymic);
            if (isValidPatronymic(student.patronymic) && isValidHyphen(student.patronymic))
            {
                break;
            }
            cout << "Ошибка! Неверное отчество. Попробуйте снова." << endl;
        }

        // Ввод специальности
        while (true)
        {
            cout << "Введите специальность: ";
            getline(cin, student.spec);
            if (isValidName(student.spec))
            {
                break;
            }
            cout << "Ошибка! Неверная специальность. Попробуйте снова." << endl;
        }

        // Ввод группы
        while (true)
        {
            cout << "Введите группу: ";
            cin >> student.group;
            if (isValidGroup(student.group))
            {
                cin.clear();
                cin.ignore(9999, '\n');
                break;
            }
            cout << "Ошибка! Неверная группа. Попробуйте снова." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

        // Ввод факультета
        while (true)
        {
            cout << "Введите факультет (ФИТ, ТОВ, ХТИТ, ПИМ, ИЭФ, ФЗО): ";
            getline(cin, student.faculty);
            if (isValidFaculty(student.faculty))
            {
                break;
            }
            cout << "Ошибка! Неверный факультет. Попробуйте снова." << endl;
        }

        // Ввод среднего балла
        while (true)
        {
            cout << "Введите средний балл: ";
            string input;
            cin >> input;

            // Проверяем, является ли ввод числом
            bool isNumber = true;
            for (char c : input)
            {
                if (!isdigit(c) && c != ',')
                {
                    isNumber = false;
                    break;
                }
            }

            if (isNumber)
            {
                try
                {
                    student.averageMarks = stof(input);                             // Преобразуем строку в число
                    student.averageMarks = round(student.averageMarks * 100) / 100; // Округление до сотых
                    if (isValidAverageMarks(student.averageMarks))
                    {
                        break;
                    }
                    else
                    {
                        cout << "Ошибка! Средний балл должен быть от 0 до 10. Попробуйте снова." << endl;
                    }
                }
                catch (const invalid_argument &)
                {
                    cout << "Ошибка! Введите числовое значение для среднего балла." << endl;
                }
            }
            else
            {
                cout << "Ошибка! Введите числовое значение для среднего балла." << endl;
            }

            cin.clear();            // Сброс состояния ошибки
            cin.ignore(9999, '\n'); // Очистка буфера
        }

        // Ввод даты поступления
        while (true)
        {
            cout << "Введите дату поступления (ДДММГГГГ): ";
            cin >> student.dateOfEntering;
            if (isValidDate(student.dateOfEntering))
            {
                cin.clear();
                cin.ignore(9999, '\n');
                break;
            }
            cout << "Ошибка! Неверная дата. Попробуйте снова." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

        students.push_back(student);
    }
}

void output(int)
{
    for (const auto &student : students)
    {
        cout << "Имя: " << student.firstName << endl;
        cout << "Фамилия: " << student.lastName << endl;
        cout << "Отчество: " << student.patronymic << endl;
        cout << "Дата поступления: " << student.dateOfEntering << endl;
        cout << "Специальность: " << student.spec << endl;
        cout << "Группа: " << student.group << endl;
        cout << "Факультет: " << student.faculty << endl;
        cout << "Средний балл: " << fixed << setprecision(2) << student.averageMarks << endl; // Округление до сотых
        cout << "-----------------------------" << endl;
    }
}

void del()
{
    string lastName;
    cout << "Введите фамилию студента для удаления: ";
    cin >> lastName;

    // Удаление всех студентов с указанной фамилией
    auto it = remove_if(students.begin(), students.end(), [lastName](const STU &student)
                        { return student.lastName == lastName; });

    if (it != students.end())
    {
        students.erase(it, students.end());
        cout << "Студент(ы) с фамилией \"" << lastName << "\" успешно удален(ы)." << endl;
    }
    else
    {
        cout << "Студент(ы) с фамилией \"" << lastName << "\" не найден(ы)." << endl;
    }
}

void find()
{
    string lastName;
    cout << "Введите фамилию студента для поиска: ";
    cin >> lastName;

    bool found = false;
    for (const auto &student : students)
    {
        if (student.lastName == lastName)
        {
            cout << "Имя: " << student.firstName << endl;
            cout << "Фамилия: " << student.lastName << endl;
            cout << "Отчество: " << student.patronymic << endl;
            cout << "Дата поступления: " << student.dateOfEntering << endl;
            cout << "Специальность: " << student.spec << endl;
            cout << "Группа: " << student.group << endl;
            cout << "Факультет: " << student.faculty << endl;
            cout << "Средний балл: " << fixed << setprecision(2) << student.averageMarks << endl; // Округление до сотых
            cout << "-----------------------------" << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Студент(ы) с фамилией \"" << lastName << "\" не найден(ы)." << endl;
    }
}

void writeToFile()
{
    ofstream file("students.txt");
    if (file.is_open())
    {
        for (const auto &student : students)
        {
            file << student.firstName << " " << student.lastName << " " << student.patronymic << " " << student.dateOfEntering << " " << student.spec << " " << student.group << " " << student.faculty << " " << fixed << setprecision(2) << student.averageMarks << endl;
        }
        file.close();
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
    }
}

void readFromFile()
{
    ifstream file("students.txt");
    if (file.is_open())
    {
        students.clear();
        STU student;
        while (file >> student.firstName >> student.lastName >> student.patronymic >> student.dateOfEntering >> student.spec >> student.group >> student.faculty >> student.averageMarks)
        {
            if (isValidName(student.firstName) && isValidName(student.lastName) && isValidPatronymic(student.patronymic) &&
                isValidDate(student.dateOfEntering) && isValidFaculty(student.faculty) &&
                isValidGroup(student.group) && isValidAverageMarks(student.averageMarks))
            {
                students.push_back(student);
            }
            else
            {
                cout << "Ошибка! Некорректные данные студента: " << student.firstName << " " << student.lastName << " в файле." << endl;
            }
        }
        file.close();
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
    }
}

void exit(int *choice)
{
    *choice = 0;
}

vector<int> splitData(string date)
{
    vector<int> temp;
    temp.push_back(stoi(date.substr(0, 2))); // day
    temp.push_back(stoi(date.substr(2, 2))); // month
    temp.push_back(stoi(date.substr(4, 4))); // year
    return temp;
}

bool isValidName(const string &name)
{
    for (char c : name)
    {
        if (dictionary.find(c) == string::npos)
        {
            return false;
        }
    }
    if (name.length() == 1 && name.front() == '-')
    {
        return false;
    }
    return true;
}
bool isValidPatronymic(const string &name)
{
    for (char c : name)
    {
        if (dictionary.find(c) == string::npos)
        {
            return false;
        }
    }
    return true;
}

bool isValidDate(const string &date)
{
    if (date.length() != 8)
    {
        return false;
    }
    for (char c : date)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(2, 2));
    int year = stoi(date.substr(4, 4));
    if (month < 1 || month > 12 || day < 1)
    {
        return false;
    }
    if (day > days_in_months[month - 1] && month != 2)
    {
        return false;
    }
    else if (month == 2 && year % 4 == 0 && day > 29)
    {
        return false;
    }
    else if (month == 2 & year % 4 != 0 && day > 28)
    {
        return false;
    }
    return true;
}

bool isValidFaculty(const string &faculty)
{
    return find(faculties.begin(), faculties.end(), faculty) != faculties.end();
}

bool isValidGroup(int group)
{
    return group > 0 && group <= 100; // Пример проверки
}

bool isValidAverageMarks(float marks)
{
    return marks >= 0 && marks <= 10; // Пример проверки
}

bool isValidHyphen(const string &name)
{
    if (name.length() == 1 && name.front() == '-')
    {
        return true;
    }
    if (name.front() == '-' || name.back() == '-')
    {
        return false;
    }
    return true;
}

bool isCorrectChoice(string &choice)
{
    for (char c : choice)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    try
    {
        int temp = stoi(choice);
    }
    catch (exception &e)
    {
        return false;
    }
    return true;
}