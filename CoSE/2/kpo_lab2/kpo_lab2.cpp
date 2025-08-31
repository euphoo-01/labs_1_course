#include <iostream>
#include <cwchar> // Для wchar_t

using namespace std;

const int N = 9;
const int X = 9 + N; // X = 18
const int Y = 10 + N; // Y = 19
const int Z = 11 + N; // Z = 20
const float S = 1.0 + N; // S = 10.0

// Пример функции для демонстрации указателей на функции
void exampleFunction() {
    cout << "Example function." << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // Задание 4
    bool first = true; // Адрес: 0000000BDFEFF304 Значение: 01
    bool second = false; // Адрес: 0000000BDFEFF324 Значение: 00

    // Задание 5
    char symbolEN = 'a'; // Адрес: 0000000BDFEFF344 Значение: 61

    // Задание 6
    char symbolRU = 'а'; // Адрес: 0000000BDFEFF364 Значение: e0
    unsigned char symbolRU2 = 'а'; // Адрес: 0000000BDFEFF384 Значение: e0

    // Задание 7
    wchar_t UTFsymbolEN = L'l'; // Адрес: 0000000BDFEFF3A4 Значение: 6c 00

    // Задание 8
    wchar_t UTFsymbolRU = L'л'; // Адрес: 0000000BDFEFF3C4 Значение: 3b 04

    // Задание 9
    short number1 = X; // Адрес: 0000000BDFEFF3E4 Значение: 12 00
    short number2 = -X; // Адрес: 0000000BDFEFF404 Значение: ee ff

    short maxShortNum = 0x7FFF; // Адрес: 0000000BDFEFF424 Значение: 32767
    short minShortNum = -0x7FFF - 1; // Адрес: 0000000BDFEFF444 Значение: -32768

    // Задание 11
    unsigned short maxUnsignedShortNum = 0xFFFF; // Адрес: 0000000BDFEFF464 Значение: 65535
    unsigned short minUnsignedShortNum = 0x0; // Адрес: 0000000BDFEFF484 Значение: 0

    // Задание 12
    int y = Y; // Адрес: 0000000BDFEFF4A4 Значение: 13 00 00 00
    int minusY = -Y; // Адрес: 0000000BDFEFF4C4 Значение: ed ff ff ff

    int maxInt = 0x7FFFFFFF; // Адрес: 0000000BDFEFF4E4 Значение: 2147483647
    int minInt = -0x7FFFFFFF - 1; // Адрес: 0000000BDFEFF504 Значение: -2147483648

    // Задание 14
    unsigned int maxUnsignedInt = 0xFFFFFFFF; // Адрес: 0000000BDFEFF524 Значение: 3435973836
    unsigned int minUnsignedInt = 0x0; // Адрес: 0000000BDFEFF544 Значение: 0

    // Задание 15
    long z = Z; // Адрес: 0000000BDFEFF564 Значение: 14 00 00 00
    long minusZ = -Z; // Адрес: 0000000BDFEFF584 Значение: ec ff ff ff

    long maxLong = 0x7FFFFFFF; // Адрес: 0000000BDFEFF5A4 Значение: 2147483647
    long minLong = -0x7FFFFFFF - 1; // Адрес: 0000000BDFEFF5C4 Значение: -2147483648

    // Задание 17
    unsigned long maxUnsignedLong = 0xFFFFFFFF; // Адрес: 0000000BDFEFF5E4 Значение: 3435973836
    unsigned long minUnsignedLong = 0x0; // Адрес: 0000000BDFEFF604 Значение: 0

    // Задание 18
    float s = S; // Адрес: 0000000BDFEFF624 Значение: 00 00 20 41
    float minusS = -S; // Адрес: 0000000BDFEFF644 Значение: 00 00 20 c1

    double dbl = 3.2222;

    //double posInfty = 1.0 / 0.0;
    //double negInfty = -1.0 / 0.0;
    //double nanInfty = 0.0 / 0.0;


    // Задание 20
    char* ptrSymbolEN = &symbolEN; // Адрес: 0000000BDFEFF688 Значение: 84 f7 7b a7 49 00 00 00
    wchar_t* ptrUTFSymbolEN = &UTFsymbolEN; // Адрес: 0000000BDFEFF6A8 Значение: e4 f7 7b a7 49 00 00 00
    short* ptrMaxShortNum = &maxShortNum; // Адрес: 0000000BDFEFF6C8 Значение: 64 f8 7b a7 49 00 00 00
    int* ptrMaxInt = &maxInt; // Адрес: 0000000BDFEFF6E8 Значение: 24 f9 7b a7 49 00 00 00
    float* ptrS = &s; // Адрес: 0000000BDFEFF708 Значение: 64 fa 7b a7 49 00 00 00
    double* ptrDbl = &dbl; // Адрес: 0000000BDFEFF728 Значение: a8 fa 7b a7 49 00 00 00

    ptrSymbolEN += 3; // Значение: d7 f4 0f 4e bd 00 00 00
    ptrUTFSymbolEN += 3; // Значение: 3a f5 0f 4e bd 00 00 00
    ptrMaxShortNum += 3; // Значение: ba f5 0f 4e bd 00 00 00
    ptrMaxInt += 3; // Значение: 80 f6 0f 4e bd 00 00 00
    ptrS += 3; // Значение: c0 f7 0f 4e bd 00 00 00
    ptrDbl += 3; // Значение: 10 f8 0f 4e bd 00 00 00

    // Задание 21
    void (*funcPtr)() = exampleFunction; // Адрес: 0000000BDFEFF748 Значение: c5 13 35 ea f7 7f 00 00
    funcPtr(); // Вызов функции через указатель


    return 0;
}