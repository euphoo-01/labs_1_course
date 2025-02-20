#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <ctype.h>
#include <wchar.h>
using namespace std;

size_t findMinWord(ifstream &);
void writeToFile(string, ofstream &);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string str;
    cout << "Введите строку: ";
    getline(cin, str);

    ofstream outFile("FILE3");
    if (outFile.is_open())
    {
        writeToFile(str, outFile);
        outFile.close();
    }
    else
    {
        cerr << "Ошибка! Не удалось открыть файл" << endl;
    }
    ifstream inFile("FILE3");
    if (inFile.is_open())
    {
        size_t minIndex = findMinWord(inFile);
        inFile.close();
    }
    else
    {
        cerr << "Ошибка! Не удалось открыть файл" << endl;
    }

    return 0;
}

size_t findMinWord(ifstream &in)
{
    const char separator = ' ';
    string str;
    size_t minIndex = 0, minSerial = 0;
    size_t minWordSize = INT_MAX;
    size_t wordIndex = 1;

    while (getline(in, str))
    {
        size_t startIndex = 0;
        while (startIndex < str.length() && str[startIndex] == separator)
        {
            startIndex++;
        }

        while (startIndex < str.length())
        {
            size_t endIndex = str.find_first_of(separator, startIndex);
            if (endIndex == string::npos)
            {
                endIndex = str.length();
            }

            size_t wordLength = endIndex - startIndex;
            bool isWord = true;
            for (size_t i = startIndex; i < endIndex; i++)
            {
                if (!iswalpha(str[i]))
                {
                    isWord = false;
                }
            }
            if (wordLength < minWordSize && wordLength > 0 && isWord)
            {
                minWordSize = wordLength;
                minSerial = wordIndex;
                minIndex = startIndex;
            }
            isWord = true;

            wordIndex++;

            startIndex = str.find_first_not_of(separator, endIndex);
        }
    }

    cout << "Порядковый номер минимального по длине слова: " << minSerial << endl;
    cout << "Размер слова минимального по длине: " << minWordSize << endl;

    return minIndex;
}
void writeToFile(string str, ofstream &out)
{
    size_t end = str.length() - 1;
    while (str[end] == ' ')
    {
        str.erase(end--);
    }
    out << str << endl;
}