#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

// ������� ��� �������� ������� ���� � ������
int countVowels(const string &line)
{
    string vowels = "����������Ũ�������aeiouAEIOU";
    int count = 0;
    for (char c : line)
    {
        if (vowels.find(c) != string::npos)
            count++;
    }
    return count;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int k;
    cout << "������� ����� ������ k (��������� � 1): ";
    cin >> k;

    ifstream file1("FILE1");
    ofstream file2("FILE2");

    if (!file1.is_open() || !file2.is_open())
    {
        cerr << "������ �������� ������!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;
    int vowelCount = 0;

    while (getline(file1, line))
    {
        if (lineNumber >= k && lineNumber <= k + 3) // �������� ������ � k �� k+3
        {
            file2 << line << endl;
            vowelCount += countVowels(line); // ������� �������
        }
        lineNumber++;
    }

    file1.close();
    file2.close();

    cout << "���������� ������� ���� � FILE2: " << vowelCount << endl;

    return 0;
}
