#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string findWordWithFirstAlphabetLetter(const string& sentence) {
    string smallestWord;
    size_t start = 0, end = 0;

    while (start < sentence.size()) {
        while (start < sentence.size() && sentence[start] == ' ') ++start; // Пропустить пробелы
        if (start >= sentence.size()) break;

        end = start;
        while (end < sentence.size() && sentence[end] != ' ') ++end;

        string currentWord = sentence.substr(start, end - start);
        if (smallestWord.empty() || currentWord < smallestWord) {
            smallestWord = currentWord;
        }

        start = end;
    }

    return smallestWord;
}


void sortWordsAlphabetically(int sentenceCount, ...) {
    char** sentences = (char**)(&sentenceCount + 1);
    string words[100];
    int wordCount = 0;

    for (int i = 0; i < sentenceCount; ++i) {
        words[wordCount++] = findWordWithFirstAlphabetLetter(sentences[i]);
    }

    // Простая сортировка пузырьком
    for (int i = 0; i < wordCount - 1; ++i) {
        for (int j = 0; j < wordCount - i - 1; ++j) {
            if (words[j] > words[j + 1]) {
                swap(words[j], words[j + 1]);
            }
        }
    }

    // Вывод результата
    for (int i = 0; i < wordCount; ++i) {
        cout << words[i] << " ";
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n1, n2, n3;

    cout << "1. Введите слова через пробел: " << endl;
    sortWordsAlphabetically(3, "hui end", "dog elephant fox", "grape house igloo");
    sortWordsAlphabetically(2, "xylophone zebra", "antelope beaver");
    sortWordsAlphabetically(4, "kite lion", "moon night", "ocean pearl", "quilt rabbit");

    return 0;
}
