#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string input;
    cout << "Введите строку (цифры и скобки): ";
    getline(cin, input);

    // Запись строки в файл FILE3
    ofstream outFile("FILE3");
    if (!outFile.is_open())
    {
        cerr << "Ошибка открытия файла FILE3 для записи!" << endl;
        return 1;
    }
    outFile << input;
    outFile.close();

    // Чтение строки из файла FILE3
    ifstream inFile("FILE3");
    if (!inFile.is_open())
    {
        cerr << "Ошибка открытия файла FILE3 для чтения!" << endl;
        return 1;
    }

    string data;
    getline(inFile, data);
    inFile.close();

    // Подсчет количества скобок
    int roundBrackets = 0, squareBrackets = 0, curlyBrackets = 0;

    for (char c : data)
    {
        if (c == '(' || c == ')')
            roundBrackets++;
        if (c == '[' || c == ']')
            squareBrackets++;
        if (c == '{' || c == '}')
            curlyBrackets++;
    }

    // Вывод результата
    cout << "Круглые скобки (): " << roundBrackets << endl;
    cout << "Квадратные скобки []: " << squareBrackets << endl;
    cout << "Фигурные скобки {}: " << curlyBrackets << endl;

    return 0;
}
