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
    cout << "������� ������: ";
    getline(cin, str);

    ofstream outFile("FILE3");
    if (outFile.is_open())
    {
        writeToFile(str, outFile);
        outFile.close();
    }
    else
    {
        cerr << "������! �� ������� ������� ����" << endl;
        return 1;
    }

    ifstream inFile("FILE3");
    if (inFile.is_open())
    {
        cout << "�����, ���������� '�':" << endl;
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

                if (temp.find('�') != string::npos || temp.find('�') != string::npos ||
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
        cerr << "������! �� ������� ������� ����" << endl;
    }

    return 0;
}

void writeToFile(const string &str, ofstream &out)
{
    out << str << endl;
}
