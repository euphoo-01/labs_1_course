#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Функция для подсчета количества гласных букв в слове
int countVowels(const string &word)
{
    string vowels = "аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouAEIOU";
    int count = 0;
    for (char c : word)
    {
        if (vowels.find(c) != string::npos)
            count++;
    }
    return count;
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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    ifstream file1("FILE1");
    ofstream file2("FILE2");

    if (!file1.is_open() || !file2.is_open())
    {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    string line;
    int maxVowelCount = 0;
    int wordNumberWithMaxVowels = -1;
    int globalWordIndex = 0; // Глобальный номер слова во всем файле

    while (getline(file1, line))
    {
        int wordCount = 0;
        int localWordIndex = 1;
        int start = 0;

        // Подсчет количества слов в строке
        while (start < line.length())
        {
            while (start < line.length() && line[start] == ' ')
                start++; // Пропускаем пробелы

            int end = line.find(' ', start);
            if (end == string::npos)
                end = line.length(); // Если пробел не найден, слово до конца строки

            if (start < line.length()) // Если нашли слово
            {

                string word = line.substr(start, end - start);
                if (isWordValid(word))
                {
                    wordCount++;
                    globalWordIndex++;
                    localWordIndex++;
                    int vowelCount = countVowels(word);
                    if (vowelCount > maxVowelCount)
                    {
                        maxVowelCount = vowelCount;
                        wordNumberWithMaxVowels = globalWordIndex;
                    }
                }
            }
            start = end + 1; // Переход к следующему слову
        }

        // Если в строке больше 2 слов, записываем её в FILE2
        if (wordCount > 2)
        {
            file2 << line << endl;
        }
    }

    file1.close();
    file2.close();

    if (wordNumberWithMaxVowels != -1)
        cout << "Номер слова в файле 1 с наибольшим количеством гласных: " << wordNumberWithMaxVowels << endl;
    else
        cout << "В файле не найдено слов с гласными." << endl;

    return 0;
}
