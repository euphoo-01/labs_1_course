#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <ctype.h>
#include <wchar.h>
using namespace std;

// Функция проверяет, является ли слово настоящим словом (без цифр)
bool isValidWord(const string &word)
{
    for (char c : word)
    {
        if (isdigit(c)) // Если в слове есть цифра, то оно не подходит
            return false;
        if (!iswalpha(c))
            return false;
    }
    return true;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string input;
    cout << "Введите строку (слова и цифры через пробел): ";
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

    ofstream outWords("FILE4");
    if (!outWords.is_open())
    {
        cerr << "Ошибка открытия файла FILE4 для записи!" << endl;
        return 1;
    }

    string word;
    cout << "Слова в строке (без цифр):" << endl;

    while (inFile >> word) // Читаем по словам
    {
        if (isValidWord(word)) // Проверяем, что слово не содержит цифр
        {
            cout << word << endl;
            outWords << word << endl; // Записываем слово в FILE2
        }
    }

    inFile.close();
    outWords.close();

    return 0;
}
