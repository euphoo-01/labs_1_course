#include "Dictionary.h"
#include "stdafx.h"
#include <windows.h>

#if (defined(TEST_CREATE_01)+defined(TEST_CREATE_02)+defined(TEST_ADDENTRY_03)+defined(TEST_ADDENTRY_04)+defined(TEST_GETENTRY_05)\
    +defined(TEST_GETENTRY_06)+defined(TEST_UPDENTRY_07)+defined(TEST_UPDENTRY_08)+defined(TEST_DICTIONARY))
#error Определено более одного макроса теста
#endif
void main() {
    setlocale(LC_ALL, "rus");
    try {
#ifdef TEST_CREATE_01
        Instance test1 = Create("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZzz", 5);
#endif
#ifdef TEST_CREATE_02
        Instance test2 = Create((char*)"test", 100000000000);
#endif
#ifdef TEST_ADDENTRY_03
        Instance test3 = Create((char*)"test", 1);
        Entry en_test3 = { 1,"zzzzzz" };
        AddEntry(test3, en_test3);
#endif
#ifdef TEST_ADDENTRY_04 
        Instance test4 = Create((char*)"test", 5);
        Entry en_test4 = { 1,"zzzzzz" };
        AddEntry(test4, en_test4);
        AddEntry(test4, en_test4);
#endif
#ifdef TEST_GETENTRY_05
        Instance test5 = Create((char*)"test", 5);
        Entry en_test5 = { 1,"zzzzzz" };
        AddEntry(test5, en_test5);
        GetEntry(test5, 2);
#endif
#ifdef TEST_GETENTRY_06
        Instance test6 = Create((char*)"test", 5);
        Entry* en_test6 = new Entry{ 1, "zzzzzz" };
        AddEntry(test6, *en_test6);
        try {
            DelEntry(test6, 2);
        }
        catch (...) {
            std::cout << THROW06 << std::endl;
        }
        delete en_test6;
#endif
#ifdef TEST_UPDENTRY_07
        Instance test7 = Create((char*)"TEST", 5);
        Entry test_e7 = { 1,"aaaaaaaaa" }, test_upd_e7 = { 2,"zzzzzzzz" };
        AddEntry(test7, test_e7);
        UpdEntry(test7, 3, test_upd_e7);
#endif
#ifdef TEST_UPDENTRY_08
        Instance test8 = Create((char*)"TEST", 5);
        Entry test_e8 = { 1,"aaaaaaaaa" }, test_upd_e8 = { 1,"zzzzzzzz" };
        AddEntry(test8, test_e8);
        UpdEntry(test8, 1, test_upd_e8);
#endif
#ifdef TEST_DICTIONARY
        dictionary::Instance d1 = dictionary::Create("Преподаватели", 5);
        dictionary::Entry e1 = { 1,"Белодед" }, e2 = { 2,"Шиман" },
            e3 = { 3,"Смелов" }, e4 = { 4,"Гончар" }, e5 = { 5,"Барковский" };
        dictionary::AddEntry(d1, e1);
        dictionary::AddEntry(d1, e2);
        dictionary::AddEntry(d1, e3);
        dictionary::AddEntry(d1, e4);
        dictionary::Entry ex2 = dictionary::GetEntry(d1, 4);
        dictionary::Print(d1);
        dictionary::DelEntry(d1, 2);
        dictionary::Print(d1);
        dictionary::Entry newEntry1 = { 6,"Королев" };
        dictionary::UpdEntry(d1, 3, newEntry1);
        dictionary::Print(d1);
        dictionary::Instance d2 = { "Cтуденты", 5 };
        dictionary::Entry s1 = { 1,"Макаревич" }, s2 = { 2,"Хаткевич" }, s3 = { 3,"Киселев" };
        dictionary::AddEntry(d2, s1);
        dictionary::AddEntry(d2, s2);
        dictionary::AddEntry(d2, s3);
        dictionary::Entry newEntry2 = { 4,"Лавшук" };
        dictionary::UpdEntry(d2, 3, newEntry2);
        dictionary::DelEntry(d2, 2);
        dictionary::Print(d2);
        Delete(d1);
        Delete(d2);
#endif
    }
    catch (char* e) {
        std::cout << e << std::endl;
    }
}