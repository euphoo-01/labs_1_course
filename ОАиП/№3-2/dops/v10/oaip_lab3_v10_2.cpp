#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

void writeToFile(const string &, ofstream &);

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
        return 1;
    }

    ifstream inFile("FILE3");
    if (inFile.is_open())
    {
        cout << "Слова, содержащие 'р':" << endl;
        while (getline(inFile, str))
        {
            size_t start = 0, end;
            while (start < str.length())
            {
                while (start < str.length() && str[start] == ' ')
                    start++;

                end = str.find(' ', start);
                if (end == string::npos)
                    end = str.length();

                string temp = str.substr(start, end - start);

                if (temp.find('р') != string::npos || temp.find('Р') != string::npos ||
                    temp.find('p') != string::npos || temp.find('P') != string::npos)
                {
                    cout << temp << endl;
                }

                start = end + 1;
            }
        }
        inFile.close();
    }
    else
    {
        cerr << "Ошибка! Не удалось открыть файл" << endl;
    }

    return 0;
}

void writeToFile(const string &str, ofstream &out)
{
    out << str << endl;
}
