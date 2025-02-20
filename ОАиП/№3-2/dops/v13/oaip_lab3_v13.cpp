#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// ������� ��� �������� ���������� ������� ���� � �����
int countVowels(const string &word)
{
    string vowels = "����������Ũ�������aeiouAEIOU";
    int count = 0;
    for (char c : word)
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

    ifstream file1("FILE1");
    ofstream file2("FILE2");

    if (!file1.is_open() || !file2.is_open())
    {
        cerr << "������ �������� ������!" << endl;
        return 1;
    }

    string line;
    int maxVowelCount = 0;
    int wordNumberWithMaxVowels = -1;
    int globalWordIndex = 1; // ���������� ����� ����� �� ���� �����

    while (getline(file1, line))
    {
        int wordCount = 0;
        int localWordIndex = 1;
        int start = 0;

        // ������� ���������� ���� � ������
        while (start < line.length())
        {
            while (start < line.length() && line[start] == ' ')
                start++; // ���������� �������

            int end = line.find(' ', start);
            if (end == string::npos)
                end = line.length(); // ���� ������ �� ������, ����� �� ����� ������

            if (start < line.length()) // ���� ����� �����
            {
                wordCount++;
                string word = line.substr(start, end - start);

                int vowelCount = countVowels(word);
                if (vowelCount > maxVowelCount)
                {
                    maxVowelCount = vowelCount;
                    wordNumberWithMaxVowels = globalWordIndex;
                }

                globalWordIndex++;
                localWordIndex++;
            }
            start = end + 1; // ������� � ���������� �����
        }

        // ���� � ������ ������ 2 ����, ���������� � � FILE2
        if (wordCount > 2)
        {
            file2 << line << endl;
        }
    }

    file1.close();
    file2.close();

    if (wordNumberWithMaxVowels != -1)
        cout << "����� ����� � ����� 1 � ���������� ����������� �������: " << wordNumberWithMaxVowels << endl;
    else
        cout << "� ����� �� ������� ���� � ��������." << endl;

    return 0;
}
