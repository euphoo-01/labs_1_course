#include <iostream>

const int N = 9;
const int X = 9 + N;
const int Y = 10 + N;
const int Z = 11 + N;
const float S = 1.0 + N;

int main()
{
    bool first = true; // 01
    bool second = false; // 00

    char symbolEN = 'a'; // 61 Windows-1251
    char symbolRU = 'а'; // -32, переполнение
    unsigned char symbolRU2 = 'а'; // eb

    wchar_t UTFsymbolEN = 'l'; // 6c UTF-8
    wchar_t UTFsymbolRU = 'л'; // eb ff UTF-8
    
    short number1 = X; // 12
    short number2 = -X; // ee ff
    return 0;
}