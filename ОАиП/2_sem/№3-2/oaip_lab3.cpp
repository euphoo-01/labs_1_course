#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <cctype>

using namespace std;

string removeExtraSpaces(const string &str)
{
    string result;
    bool space = false;
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
    if (!result.empty() && result.back() == ' ')
    {
        result.pop_back();
    }
    return result;
}

int countWords(const string &);
bool isWordValid(const string &);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream inFile("FILE1");
    ofstream outFile("FILE2");

    if (!inFile.is_open() || !outFile.is_open())
    {
        cout << "Ошибка! Не удалось открыть файл..." << endl;
        return 1;
    }

    string line;
    int wordCount = 0;
    int lineCount = 0;
    bool copy = false;
    int N1, N2;

    cout << "Введите N1: ";
    cin >> N1;
    cout << "Введите N2: ";
    cin >> N2;

    while (getline(inFile, line))
    {
        lineCount++;
        if (lineCount >= N1 && lineCount <= N2 &&
            (line[0] == 'C' || line[0] == 'c' || line[0] == 'С' || line[0] == 'с'))
        {

            line = removeExtraSpaces(line);
            outFile << line << endl;

            if (!copy)
            {
                wordCount = countWords(line);
                copy = true;
            }
        }
    }
    inFile.close();
    outFile.close();

    if (copy)
    {
        cout << "Количество слов в первой строке FILE2: " << wordCount << endl;
    }
    else
    {
        cout << "В FILE2 не записано ни одной строки, соответствующей условиям." << endl;
    }

    return 0;
}

bool isWordValid(const string &word)
{
    for (char ch : word)
    {
        if (!isalpha(static_cast<unsigned char>(ch)))
        {
            return false;
        }
    }
    return true;
}

int countWords(const string &str)
{
    size_t start = 0, end;
    int counter = 0;

    while (start < str.length())
    {
        while (start < str.length() && str[start] == ' ')
        {
            start++;
        }
        if (start >= str.length())
        {
            break;
        }
        end = str.find(' ', start);
        if (end == string::npos)
        {
            end = str.length();
        }
        if (isWordValid(str.substr(start, end - start)))
        {
            counter++;
        }
        start = end + 1;
    }
    return counter;
}