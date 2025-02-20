#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <ctype.h>
#include <wchar.h>
using namespace std;

// ������� ���������, �������� �� ����� ��������� ������ (��� ����)
bool isValidWord(const string &word)
{
    for (char c : word)
    {
        if (isdigit(c)) // ���� � ����� ���� �����, �� ��� �� ��������
            return false;
        if (!iswalpha(c))
            return false;
    }
    return true;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string input;
    cout << "������� ������ (����� � ����� ����� ������): ";
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

    ofstream outWords("FILE4");
    if (!outWords.is_open())
    {
        cerr << "������ �������� ����� FILE4 ��� ������!" << endl;
        return 1;
    }

    string word;
    cout << "����� � ������ (��� ����):" << endl;

    while (inFile >> word) // ������ �� ������
    {
        if (isValidWord(word)) // ���������, ��� ����� �� �������� ����
        {
            cout << word << endl;
            outWords << word << endl; // ���������� ����� � FILE2
        }
    }

    inFile.close();
    outWords.close();

    return 0;
}
