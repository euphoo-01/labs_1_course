#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

bool isWordValid(string word);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream inFile("FILE1");
    ofstream outFile("FILE2");

    string consonantENLetters = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
    string consonantRULetters = "������������������������������������������";

    if (inFile.is_open() && outFile.is_open())
    {
        string line;
        string firstWord;
        int lineCouner = 0;
        int consonantCount = 0;
        while (getline(inFile, line))
        {
            if (lineCouner == 0)
            {
                firstWord = line.substr(0, line.find(' '));
                lineCouner++;
            }
            else
            {
                if (line.find(firstWord) == string::npos)
                {
                    outFile << line << endl;

                    if (lineCouner == 1)
                    { // ���� ��������� ������ ������ � ����� FILE2
                        for (wchar_t c : line)
                            if (consonantENLetters.find_first_of(c) != string::npos || consonantRULetters.find_first_of(c) != string::npos)
                            { // ���� ������ ������� � ������ � ���������� �������
                                consonantCount++;
                            }
                    }
                }
                lineCouner++;
            }
        }
        cout << "���������� ��������� ���� � ������ ������ FILE2: " << consonantCount << endl;
    }
    else
    {
        cerr << "������! �� ������� ������� ����..." << endl;
    }
    return 0;
}

bool isWordValid(string word)
{
    for (char ch : word)
    {
        if (!iswalpha(ch))
        {
            return false;
        }
        else if (isdigit(ch))
        {
            return false;
        }
    }
    return true;
}