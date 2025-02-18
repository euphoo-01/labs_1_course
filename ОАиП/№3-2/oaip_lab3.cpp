#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <cstdlib>
using namespace std;

const int N1 = 1;
const int N2 = 3;

// ������� 9
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream inFile("FILE1");
    ofstream outFile("FILE2");

    string line;
    int wordCount = 0;
    int lineCount = 0;
    bool copy = false;

    if (inFile.is_open() && outFile.is_open())
    {
        while (getline(inFile, line))
        {
            lineCount++;
            if (lineCount >= N1 && lineCount <= N2)
            {
                if ((line[0] == 'C' || line[0] == 'c') || (line[0] == '�' || line[0] == '�'))
                {
                    outFile << line << endl;
                    if (!copy)
                    {
                        wordCount = count(line.begin(), line.end(), ' ') + 1;
                        copy = true;
                    }
                }
            }
        }
        inFile.close();
        outFile.close();
        cout << "���������� ���� � ������ ������ FILE2: " << wordCount << endl;
    }
    else
    {
        cout << "������! �� ������� ������� ����...";
    }

    return 0;
}
