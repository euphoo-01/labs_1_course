#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


// 1.	В заданной последовательности слов найти все слова, имеющие заданное окончание.
int dop1() {
    char input[128];
    char ending[128];
    cout << "Введите последовательность слов: ";
    gets_s(input, sizeof(input));

    cout << "Введите окончание: ";
    gets_s(ending, sizeof(ending));

    size_t endingLen = strlen(ending);
    size_t inputLen = strlen(input);

    cout << "Слова с окончанием \"" << ending << "\":\n";

    char word[128];
    size_t wordIndex = 0;

    for (size_t i = 0; i <= inputLen; ++i) {

        if (input[i] == ' ' || input[i] == '\0') {
            if (wordIndex > 0) { // Если слово не пустое
                word[wordIndex] = '\0'; // Завершаем строку
                size_t wordLen = strlen(word);

                // Проверяем окончание
                if (wordLen >= endingLen) {
                    bool matches = true;
                    for (size_t j = 0; j < endingLen; ++j) {
                        if (word[wordLen - endingLen + j] != ending[j]) {
                            matches = false;
                            break;
                        }
                    }

                    if (matches) {
                        cout << word << endl;
                    }
                }
            }
            wordIndex = 0;
        }
        else {
            // Записываем символ в текущее слово
            word[wordIndex++] = input[i];
        }
    }

    return 0;
}

// 3.	Из заданного предложения удалить те слова, которые уже встречались в предложении раньше.
int dop3() {
    char sentence[128]; 
    char result[128] = "";
    char words[128][128];  // Массив для хранения слов
    int wordCount = 0;  // Количество уникальных слов в предложении

    cout << "Введите предложение: ";
    gets_s(sentence, sizeof(sentence));

    const char* start = sentence;  // Указатель на начало слова
    const char* ptr = sentence;  // Указатель для перебора строки

    while (*ptr) {
        if (*ptr == ' ' || *(ptr + 1) == '\0') {
            // Определяем длину текущего слова
            size_t len = ptr - start + (*(ptr + 1) == '\0' ? 1 : 0);

            bool alreadyExists = false;

            for (int i = 0; i < wordCount; ++i) {
                bool match = true;
                for (size_t j = 0; j < len; ++j) {
                    if (words[i][j] != *(start + j)) {
                        match = false;
                        break;
                    }
                }
                if (match && strlen(words[i]) == len) {
                    alreadyExists = true;
                    break;
                }
            }

            if (!alreadyExists) {
                for (size_t i = 0; i < len; ++i) {
                    words[wordCount][i] = *(start + i); 
                }
                words[wordCount][len] = '\0';
                wordCount++;

                // Добавляем слово в результат
                if (strlen(result) > 0) {
                    result[strlen(result)] = ' '; 
                }
                for (size_t i = 0; i < len; ++i) {
                    result[strlen(result)] = *(start + i); 
                }
                result[strlen(result)] = '\0'; 
            }

            start = ptr + 1;
        }
        ptr++;
    }

    cout << "Результат: " << result << endl;
    return 0;
}


// 5.	Даны два предложения. Найти самое короткое из слов первого предложения, которого нет во втором предложении.
int dop5() {
    char sentence1[128], sentence2[128];  // Два предложения
    char words1[128][128];  // Массив для слов первого предложения
    char words2[128][128];  // Массив для слов второго предложения
    int wordCount1 = 0, wordCount2 = 0;  // Количество слов в предложениях

    cout << "Введите первое предложение: ";
    gets_s(sentence1, sizeof(sentence1));

    cout << "Введите второе предложение: ";
    gets_s(sentence2, sizeof(sentence2));

    // Разбиваем первое предложение на слова
    const char* start1 = sentence1;
    const char* ptr1 = sentence1;
    while (*ptr1) {
        if (*ptr1 == ' ' || *(ptr1 + 1) == '\0') {
            size_t len = ptr1 - start1 + (*(ptr1 + 1) == '\0' ? 1 : 0);

            // Копируем слово в массив words1
            for (size_t i = 0; i < len; ++i) {
                words1[wordCount1][i] = *(start1 + i);
            }
            words1[wordCount1][len] = '\0';
            wordCount1++;

            start1 = ptr1 + 1;
        }
        ptr1++;
    }

    // Разбиваем второе предложение на слова
    const char* start2 = sentence2;
    const char* ptr2 = sentence2;
    while (*ptr2) {
        if (*ptr2 == ' ' || *(ptr2 + 1) == '\0') {
            size_t len = ptr2 - start2 + (*(ptr2 + 1) == '\0' ? 1 : 0);

            // Копируем слово в массив words2
            for (size_t i = 0; i < len; ++i) {
                words2[wordCount2][i] = *(start2 + i);
            }
            words2[wordCount2][len] = '\0';
            wordCount2++;

            start2 = ptr2 + 1;
        }
        ptr2++;
    }

    // Ищем самое короткое слово из первого предложения, которого нет во втором
    char shortestWord[128] = "";
    size_t shortestLength = 128;

    for (int i = 0; i < wordCount1; ++i) {
        bool existsInSecond = false;

        // Проверяем, есть ли слово во втором предложении
        for (int j = 0; j < wordCount2; ++j) {
            bool match = true;
            size_t len1 = strlen(words1[i]);
            size_t len2 = strlen(words2[j]);

            if (len1 == len2) {
                for (size_t k = 0; k < len1; ++k) {
                    if (words1[i][k] != words2[j][k]) {
                        match = false;
                        break;
                    }
                }
            }
            else {
                match = false;
            }

            if (match) {
                existsInSecond = true;
                break;
            }
        }

        // Если слово не найдено во втором предложении и оно короче, чем текущее найденное
        if (!existsInSecond && strlen(words1[i]) < shortestLength) {
            shortestLength = strlen(words1[i]);
            for (size_t k = 0; k <= shortestLength; ++k) {
                shortestWord[k] = words1[i][k];
            }
        }
    }

    if (shortestLength == 128) {
        cout << "Нет слов из первого предложения, отсутствующих во втором." << endl;
    }
    else {
        cout << "Самое короткое слово из первого предложения, которого нет во втором: " << shortestWord << endl;
    }

    return 0;
}
int main() {
	system("chcp 1251");

    // dop1();
    // dop3();
    dop5();

	return 0;
}