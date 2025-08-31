#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char input[256];
    char first[256] = { 0 };
    char second[256] = { 0 };
    int k;

    printf("Введите строку: ");
    gets_s(input, sizeof(input));

    size_t len = strlen(input);

    printf("Введите длину первой подстроки (k): ");
    cin >> k;

    size_t i = 0;
    size_t lastSpace = 0;

    for (i = 0; i < (size_t)k && i < len; ++i) {
        if (*(input + i) == ' ') {
            lastSpace = i;
        }
    }

    if (i < len && *(input + i) != ' ' && lastSpace > 0) {
        k = lastSpace;
    }

    char* pFirst = first;
    for (i = 0; i < (size_t)k && i < len; i++) {
        *(pFirst++) = *(input + i);
    }
    *pFirst = '\0';

    if ((size_t)k < len) {
        char* pSecond = second;
        size_t start = k + (*(input + k) == ' ' ? 1 : 0);
        for (i = start; i < len; i++) {
            *(pSecond++) = *(input + i);
        }
        *pSecond = '\0';
    }

    printf("Первая подстрока: \"%s\"\n", first);
    printf("Вторая подстрока: \"%s\"\n", second);

    return 0;
}
