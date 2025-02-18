#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

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
                firstWord = line.substr(0, line.find(' '));
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
                        {
                            if (consonantENLetters.find(c) == string::npos && consonantRULetters.find(c) == string::npos)
                            { // Если символ имеется в строке с согласными буквами
                                consonantCount++;
                            }
                        }
                    }
                    lineCouner++;
                }
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