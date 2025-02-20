#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N1 = 1;
const int N2 = 5;

string removeExtraSpaces(const string &str)
{
    string result;
    bool space = false; // Флаг, чтобы не допускать подряд идущие пробелы

    for (char ch : str)
    {
        if (ch != ' ')
        {
            result += ch;
            space = false;
        }
        else if (!space)
        {
            result += ' ';
            space = true;
        }
    }

    // Удаление возможного пробела в конце
    if (!result.empty() && result.back() == ' ')
    {
        while (result.back() == ' ')
        {
            result.pop_back();
        }
    }

    return result;
}

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
                if ((line[0] == 'C' || line[0] == 'c') || (line[0] == 'с' || line[0] == 'С'))
                {
                    line = removeExtraSpaces(line); // Удаление лишних пробелов
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
        cout << "Количество слов в первой строке FILE2: " << wordCount << endl;
    }
    else
    {
        cout << "Ошибка! Не удалось открыть файл...";
    }

    return 0;
}
