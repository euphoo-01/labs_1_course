#include <iostream>
#include <string>
#include <windows.h>
#include <stdarg.h>

// Написать функцию, которая находит в строке слово с самой первой по алфавиту буквы. 
// С ее помощью реализовать размещение слов в выходной строке в алфавитном порядке.

using namespace std;

void sortWords (int wordCount, ...);
string findEarliestWord(const string& text);

int main() {
    system("chcp 1251");

    sortWords(3, "privet", "hello", "world");

    sortWords(4, "localhost", "javascript", "c++", "php");

    sortWords(5, "blueberries", "draniki", "apple", "cake", "malina");

    return 0;
}


void sortWords (int wordCount, ...) {
    string input{}, output{};

    va_list args;
    va_start(args, wordCount);
    for (int i = 0; i < wordCount; ++i) {
        const char* word = va_arg(args, const char*);
        input += word;
        input += ' ';
    }
    va_end(args);

    for (int i = 0; i < wordCount; i++) {
        string word = findEarliestWord(input);
        output += word + ' ';

        size_t pos = input.find(word);
        input.erase(pos,word.length());
    }

    cout << output << endl;
}

string findEarliestWord(const string& text) {
    string word, earliestWord;
    char earliestChar = 'z' + 1;

    for (size_t i = 0; i < text.size(); ++i) {
        if (isalpha(text[i])) { // isalpha возвращает true, если текущий char содержит символ
            char firstChar = tolower(text[i]);
            size_t start = i;

            while (i < text.size() && !isspace(text[i])) {
                ++i;
            }

            if (firstChar < earliestChar) {
                earliestChar = firstChar;
                earliestWord = text.substr(start, i - start);
            }
        }
    }

    return earliestWord;
}