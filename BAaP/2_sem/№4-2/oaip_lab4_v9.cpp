#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <locale>
#include <iomanip> // ��� ���������� �������� �����

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
string dictionary = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ�������������������������������������Ũ��������������������������-";
vector<string> faculties = {"���", "����", "���", "���", "���", "���", "���"};

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
    SetConsoleOutputCP(1251); // ��������� ��������� ������� ��� ������
    SetConsoleCP(1251);       // ��������� ��������� ������� ��� �����
    setlocale(LC_ALL, "Russian");

    int choice = -1;
    string choice_str;
    do
    {
        cout << "���� ����������: \n 0) ����� �� ��������� \n 1) ������ ������ �������� \n 2) ������� ������ �������� \n 3) ������� ������ � �������� \n 4) ����� �������� \n 5) ��������� ���������� � ���� \n 6) ��������� ���������� �� ����� \n��� �����: ";
        getline(cin, choice_str);
        if (isCorrectChoice(choice_str))
        {
            choice = stoi(choice_str);
            switch (choice)
            {
            case 1:
            {
            exc_start:
                cout << "������� ������� �� ������ ��������? ";
                string count_str;
                try
                {
                    while (!(getline(cin, count_str)) || stoi(count_str) <= 0 || !all_of(count_str.begin(), count_str.end(), ::isdigit))
                    {
                        cout << "������! ������� ���������� ���������� ���������: ";
                    }
                    input(stoi(count_str));
                }
                catch (exception &e)
                {
                    cerr << "������! " << endl;
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
                cout << "������! ������ �������� ���." << endl;
                break;
            }
        }
        else
        {
            cerr << "������� ���������� �����!" << endl;
        }
    } while (choice != 0);
    return 0;
}

void input(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "������� ������ ��������: " << endl;
        STU student;

        // ���� �����
        while (true)
        {
            cout << "������� ���: ";
            getline(cin, student.firstName);
            if (isValidName(student.firstName) && isValidHyphen(student.firstName))
            {
                break;
            }
            cout << "������! �������� ���. ���������� �����." << endl;
        }

        // ���� �������
        while (true)
        {
            cout << "������� �������: ";
            getline(cin, student.lastName);
            if (isValidName(student.lastName) && isValidHyphen(student.lastName))
            {
                break;
            }
            cout << "������! �������� �������. ���������� �����." << endl;
        }

        // ���� ��������
        while (true)
        {
            cout << "������� ��������: ";
            getline(cin, student.patronymic);
            if (isValidPatronymic(student.patronymic) && isValidHyphen(student.patronymic))
            {
                break;
            }
            cout << "������! �������� ��������. ���������� �����." << endl;
        }

        // ���� �������������
        while (true)
        {
            cout << "������� �������������: ";
            getline(cin, student.spec);
            if (isValidName(student.spec))
            {
                break;
            }
            cout << "������! �������� �������������. ���������� �����." << endl;
        }

        // ���� ������
        while (true)
        {
            cout << "������� ������: ";
            cin >> student.group;
            if (isValidGroup(student.group))
            {
                cin.clear();
                cin.ignore(9999, '\n');
                break;
            }
            cout << "������! �������� ������. ���������� �����." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

        // ���� ����������
        while (true)
        {
            cout << "������� ��������� (���, ���, ����, ���, ���, ���): ";
            getline(cin, student.faculty);
            if (isValidFaculty(student.faculty))
            {
                break;
            }
            cout << "������! �������� ���������. ���������� �����." << endl;
        }

        // ���� �������� �����
        while (true)
        {
            cout << "������� ������� ����: ";
            string input;
            cin >> input;

            // ���������, �������� �� ���� ������
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
                    student.averageMarks = stof(input);                             // ����������� ������ � �����
                    student.averageMarks = round(student.averageMarks * 100) / 100; // ���������� �� �����
                    if (isValidAverageMarks(student.averageMarks))
                    {
                        break;
                    }
                    else
                    {
                        cout << "������! ������� ���� ������ ���� �� 0 �� 10. ���������� �����." << endl;
                    }
                }
                catch (const invalid_argument &)
                {
                    cout << "������! ������� �������� �������� ��� �������� �����." << endl;
                }
            }
            else
            {
                cout << "������! ������� �������� �������� ��� �������� �����." << endl;
            }

            cin.clear();            // ����� ��������� ������
            cin.ignore(9999, '\n'); // ������� ������
        }

        // ���� ���� �����������
        while (true)
        {
            cout << "������� ���� ����������� (��������): ";
            cin >> student.dateOfEntering;
            if (isValidDate(student.dateOfEntering))
            {
                cin.clear();
                cin.ignore(9999, '\n');
                break;
            }
            cout << "������! �������� ����. ���������� �����." << endl;
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
        cout << "���: " << student.firstName << endl;
        cout << "�������: " << student.lastName << endl;
        cout << "��������: " << student.patronymic << endl;
        cout << "���� �����������: " << student.dateOfEntering << endl;
        cout << "�������������: " << student.spec << endl;
        cout << "������: " << student.group << endl;
        cout << "���������: " << student.faculty << endl;
        cout << "������� ����: " << fixed << setprecision(2) << student.averageMarks << endl; // ���������� �� �����
        cout << "-----------------------------" << endl;
    }
}

void del()
{
    string lastName;
    cout << "������� ������� �������� ��� ��������: ";
    cin >> lastName;

    // �������� ���� ��������� � ��������� ��������
    auto it = remove_if(students.begin(), students.end(), [lastName](const STU &student)
                        { return student.lastName == lastName; });

    if (it != students.end())
    {
        students.erase(it, students.end());
        cout << "�������(�) � �������� \"" << lastName << "\" ������� ������(�)." << endl;
    }
    else
    {
        cout << "�������(�) � �������� \"" << lastName << "\" �� ������(�)." << endl;
    }
}

void find()
{
    string lastName;
    cout << "������� ������� �������� ��� ������: ";
    cin >> lastName;

    bool found = false;
    for (const auto &student : students)
    {
        if (student.lastName == lastName)
        {
            cout << "���: " << student.firstName << endl;
            cout << "�������: " << student.lastName << endl;
            cout << "��������: " << student.patronymic << endl;
            cout << "���� �����������: " << student.dateOfEntering << endl;
            cout << "�������������: " << student.spec << endl;
            cout << "������: " << student.group << endl;
            cout << "���������: " << student.faculty << endl;
            cout << "������� ����: " << fixed << setprecision(2) << student.averageMarks << endl; // ���������� �� �����
            cout << "-----------------------------" << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "�������(�) � �������� \"" << lastName << "\" �� ������(�)." << endl;
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
        cout << "������ �������� �����!" << endl;
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
                cout << "������! ������������ ������ ��������: " << student.firstName << " " << student.lastName << " � �����." << endl;
            }
        }
        file.close();
    }
    else
    {
        cout << "������ �������� �����!" << endl;
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
    return group > 0 && group <= 100; // ������ ��������
}

bool isValidAverageMarks(float marks)
{
    return marks >= 0 && marks <= 10; // ������ ��������
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