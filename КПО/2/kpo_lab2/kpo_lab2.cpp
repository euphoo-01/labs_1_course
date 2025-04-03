п»ї#include <iostream>
#include <cwchar> // Р”Р»СЏ wchar_t

using namespace std;

const int N = 9;
const int X = 9 + N; // X = 18
const int Y = 10 + N; // Y = 19
const int Z = 11 + N; // Z = 20
const float S = 1.0 + N; // S = 10.0

// РџСЂРёРјРµСЂ С„СѓРЅРєС†РёРё РґР»СЏ РґРµРјРѕРЅСЃС‚СЂР°С†РёРё СѓРєР°Р·Р°С‚РµР»РµР№ РЅР° С„СѓРЅРєС†РёРё
void exampleFunction() {
    cout << "Example function." << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // Р—Р°РґР°РЅРёРµ 4
    bool first = true; // РђРґСЂРµСЃ: 0000000BDFEFF304 Р—РЅР°С‡РµРЅРёРµ: 01
    bool second = false; // РђРґСЂРµСЃ: 0000000BDFEFF324 Р—РЅР°С‡РµРЅРёРµ: 00

    // Р—Р°РґР°РЅРёРµ 5
    char symbolEN = 'a'; // РђРґСЂРµСЃ: 0000000BDFEFF344 Р—РЅР°С‡РµРЅРёРµ: 61

    // Р—Р°РґР°РЅРёРµ 6
    char symbolRU = 'Р°'; // РђРґСЂРµСЃ: 0000000BDFEFF364 Р—РЅР°С‡РµРЅРёРµ: e0
    unsigned char symbolRU2 = 'Р°'; // РђРґСЂРµСЃ: 0000000BDFEFF384 Р—РЅР°С‡РµРЅРёРµ: e0

    // Р—Р°РґР°РЅРёРµ 7
    wchar_t UTFsymbolEN = L'l'; // РђРґСЂРµСЃ: 0000000BDFEFF3A4 Р—РЅР°С‡РµРЅРёРµ: 6c 00

    // Р—Р°РґР°РЅРёРµ 8
    wchar_t UTFsymbolRU = L'Р»'; // РђРґСЂРµСЃ: 0000000BDFEFF3C4 Р—РЅР°С‡РµРЅРёРµ: 3b 04

    // Р—Р°РґР°РЅРёРµ 9
    short number1 = X; // РђРґСЂРµСЃ: 0000000BDFEFF3E4 Р—РЅР°С‡РµРЅРёРµ: 12 00
    short number2 = -X; // РђРґСЂРµСЃ: 0000000BDFEFF404 Р—РЅР°С‡РµРЅРёРµ: ee ff

    short maxShortNum = 0x7FFF; // РђРґСЂРµСЃ: 0000000BDFEFF424 Р—РЅР°С‡РµРЅРёРµ: 32767
    short minShortNum = -0x7FFF - 1; // РђРґСЂРµСЃ: 0000000BDFEFF444 Р—РЅР°С‡РµРЅРёРµ: -32768

    // Р—Р°РґР°РЅРёРµ 11
    unsigned short maxUnsignedShortNum = 0xFFFF; // РђРґСЂРµСЃ: 0000000BDFEFF464 Р—РЅР°С‡РµРЅРёРµ: 65535
    unsigned short minUnsignedShortNum = 0x0; // РђРґСЂРµСЃ: 0000000BDFEFF484 Р—РЅР°С‡РµРЅРёРµ: 0

    // Р—Р°РґР°РЅРёРµ 12
    int y = Y; // РђРґСЂРµСЃ: 0000000BDFEFF4A4 Р—РЅР°С‡РµРЅРёРµ: 13 00 00 00
    int minusY = -Y; // РђРґСЂРµСЃ: 0000000BDFEFF4C4 Р—РЅР°С‡РµРЅРёРµ: ed ff ff ff

    int maxInt = 0x7FFFFFFF; // РђРґСЂРµСЃ: 0000000BDFEFF4E4 Р—РЅР°С‡РµРЅРёРµ: 2147483647
    int minInt = -0x7FFFFFFF - 1; // РђРґСЂРµСЃ: 0000000BDFEFF504 Р—РЅР°С‡РµРЅРёРµ: -2147483648

    // Р—Р°РґР°РЅРёРµ 14
    unsigned int maxUnsignedInt = 0xFFFFFFFF; // РђРґСЂРµСЃ: 0000000BDFEFF524 Р—РЅР°С‡РµРЅРёРµ: 3435973836
    unsigned int minUnsignedInt = 0x0; // РђРґСЂРµСЃ: 0000000BDFEFF544 Р—РЅР°С‡РµРЅРёРµ: 0

    // Р—Р°РґР°РЅРёРµ 15
    long z = Z; // РђРґСЂРµСЃ: 0000000BDFEFF564 Р—РЅР°С‡РµРЅРёРµ: 14 00 00 00
    long minusZ = -Z; // РђРґСЂРµСЃ: 0000000BDFEFF584 Р—РЅР°С‡РµРЅРёРµ: ec ff ff ff

    long maxLong = 0x7FFFFFFF; // РђРґСЂРµСЃ: 0000000BDFEFF5A4 Р—РЅР°С‡РµРЅРёРµ: 2147483647
    long minLong = -0x7FFFFFFF - 1; // РђРґСЂРµСЃ: 0000000BDFEFF5C4 Р—РЅР°С‡РµРЅРёРµ: -2147483648

    // Р—Р°РґР°РЅРёРµ 17
    unsigned long maxUnsignedLong = 0xFFFFFFFF; // РђРґСЂРµСЃ: 0000000BDFEFF5E4 Р—РЅР°С‡РµРЅРёРµ: 3435973836
    unsigned long minUnsignedLong = 0x0; // РђРґСЂРµСЃ: 0000000BDFEFF604 Р—РЅР°С‡РµРЅРёРµ: 0

    // Р—Р°РґР°РЅРёРµ 18
    float s = S; // РђРґСЂРµСЃ: 0000000BDFEFF624 Р—РЅР°С‡РµРЅРёРµ: 00 00 20 41
    float minusS = -S; // РђРґСЂРµСЃ: 0000000BDFEFF644 Р—РЅР°С‡РµРЅРёРµ: 00 00 20 c1

    double dbl = 3.2222;

    //double posInfty = 1.0 / 0.0;
    //double negInfty = -1.0 / 0.0;
    //double nanInfty = 0.0 / 0.0;


    // Р—Р°РґР°РЅРёРµ 20
    char* ptrSymbolEN = &symbolEN; // РђРґСЂРµСЃ: 0000000BDFEFF688 Р—РЅР°С‡РµРЅРёРµ: 84 f7 7b a7 49 00 00 00
    wchar_t* ptrUTFSymbolEN = &UTFsymbolEN; // РђРґСЂРµСЃ: 0000000BDFEFF6A8 Р—РЅР°С‡РµРЅРёРµ: e4 f7 7b a7 49 00 00 00
    short* ptrMaxShortNum = &maxShortNum; // РђРґСЂРµСЃ: 0000000BDFEFF6C8 Р—РЅР°С‡РµРЅРёРµ: 64 f8 7b a7 49 00 00 00
    int* ptrMaxInt = &maxInt; // РђРґСЂРµСЃ: 0000000BDFEFF6E8 Р—РЅР°С‡РµРЅРёРµ: 24 f9 7b a7 49 00 00 00
    float* ptrS = &s; // РђРґСЂРµСЃ: 0000000BDFEFF708 Р—РЅР°С‡РµРЅРёРµ: 64 fa 7b a7 49 00 00 00
    double* ptrDbl = &dbl; // РђРґСЂРµСЃ: 0000000BDFEFF728 Р—РЅР°С‡РµРЅРёРµ: a8 fa 7b a7 49 00 00 00

    ptrSymbolEN += 3; // Р—РЅР°С‡РµРЅРёРµ: d7 f4 0f 4e bd 00 00 00
    ptrUTFSymbolEN += 3; // Р—РЅР°С‡РµРЅРёРµ: 3a f5 0f 4e bd 00 00 00
    ptrMaxShortNum += 3; // Р—РЅР°С‡РµРЅРёРµ: ba f5 0f 4e bd 00 00 00
    ptrMaxInt += 3; // Р—РЅР°С‡РµРЅРёРµ: 80 f6 0f 4e bd 00 00 00
    ptrS += 3; // Р—РЅР°С‡РµРЅРёРµ: c0 f7 0f 4e bd 00 00 00
    ptrDbl += 3; // Р—РЅР°С‡РµРЅРёРµ: 10 f8 0f 4e bd 00 00 00

    // Р—Р°РґР°РЅРёРµ 21
    void (*funcPtr)() = exampleFunction; // РђРґСЂРµСЃ: 0000000BDFEFF748 Р—РЅР°С‡РµРЅРёРµ: c5 13 35 ea f7 7f 00 00
    funcPtr(); // Р’С‹Р·РѕРІ С„СѓРЅРєС†РёРё С‡РµСЂРµР· СѓРєР°Р·Р°С‚РµР»СЊ


    return 0;
}