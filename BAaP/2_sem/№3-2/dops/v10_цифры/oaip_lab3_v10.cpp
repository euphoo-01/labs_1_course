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
    string consonantRULetters = "БВГДЖЗЙКЛМНПРСТФЗЦЧШЩбвгджзйклмнпрстфзцчшщ";

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
                size_t start = 0, end = line.find_first_of(' ');
                firstWord = line.substr(start, end);
                while (!isWordValid(firstWord) && end < line.length())
                {
                    start = line.find_first_of(' ', start + 1);
                    end = line.find_first_of(' ', start + 1);
                    firstWord = line.substr(start + 1, end - start - 1);
                }

                lineCouner++;
            }
            else
            {
                if (line.find(firstWord) == string::npos)
                {
                    outFile << line << endl;

                    if (lineCouner == 1)
                    { // Если создалась первая строка в файле FILE2
                        for (wchar_t c : line)
                            if (consonantENLetters.find_first_of(c) != string::npos || consonantRULetters.find_first_of(c) != string::npos)
                            { // Если символ имеется в строке с согласными буквами
                                consonantCount++;
                            }
                    }
                }
                lineCouner++;
            }
        }
        cout << "Количество согласных букв в первой строке FILE2: " << consonantCount << endl;
    }
    else
    {
        cerr << "Ошибка! Не удалось открыть файл..." << endl;
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