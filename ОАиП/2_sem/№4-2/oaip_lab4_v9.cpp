#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

typedef struct Students
{
    string firstName;
    string lastName;
    string otchestvo;
    int dateOfEntering;
    string spec;
    int group;
    int faculty;
    int averageMarks;
} STU;

void input(int);
void output(int);
void del();
void find();
void writeToFile();
void readFromFile();

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    int choice;
    do
    {
        cout << "���� ����������: \n 0) ����� �� ��������� \n 1) ������ ������ �������� \n 2) ������� ������ �������� \n 3) ������� ������ � �������� \n 4) ����� �������� \n 5) ��������� ���������� � ���� \n 6) ������� ���������� �� ����� \n ��� �����: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            input(choice);
            break;
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
    } while (choice != 0);
    return 0;
}