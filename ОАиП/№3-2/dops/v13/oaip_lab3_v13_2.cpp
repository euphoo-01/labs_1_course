#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string input;
    cout << "������� ������ (����� � ������): ";
    getline(cin, input);

    // ������ ������ � ���� FILE3
    ofstream outFile("FILE3");
    if (!outFile.is_open())
    {
        cerr << "������ �������� ����� FILE3 ��� ������!" << endl;
        return 1;
    }
    outFile << input;
    outFile.close();

    // ������ ������ �� ����� FILE3
    ifstream inFile("FILE3");
    if (!inFile.is_open())
    {
        cerr << "������ �������� ����� FILE3 ��� ������!" << endl;
        return 1;
    }

    string data;
    getline(inFile, data);
    inFile.close();

    // ������� ���������� ������
    int roundBrackets = 0, squareBrackets = 0, curlyBrackets = 0;

    for (char c : data)
    {
        if (c == '(' || c == ')')
            roundBrackets++;
        if (c == '[' || c == ']')
            squareBrackets++;
        if (c == '{' || c == '}')
            curlyBrackets++;
    }

    // ����� ����������
    cout << "������� ������ (): " << roundBrackets << endl;
    cout << "���������� ������ []: " << squareBrackets << endl;
    cout << "�������� ������ {}: " << curlyBrackets << endl;

    return 0;
}
