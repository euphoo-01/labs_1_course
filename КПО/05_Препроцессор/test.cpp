#include "stdafx.h"
#include <iostream>

using namespace Dictionary;
using namespace std;

// Макросы для тестирования
#define TEST_CREATE_01
#define TEST_CREATE_02
#define TEST_ADDENTRY_03
#define TEST_ADDENTRY_04
#define TEST_GETENTRY_05
#define TEST_GETENTRY_06
#define TEST_UPDENTRY_07
#define TEST_UPDENTRY_08
#define TEST_DICTIONARY

void testCreate01() {
#ifdef TEST_CREATE_01
    cout << "\nТЕСТ CREATE_01: Проверка генерации исключения THROW01" << endl;
    try {
        char longName[100] = "ThisNameIsTooLongForDictionaryAndShouldGenerateAnException";
        Instance dict = Create(longName, 10);
        cout << "ОШИБКА: Исключение не было сгенерировано" << endl;
    }
    catch (exception& e) {
        cout << "УСПЕХ: Перехвачено исключение: " << e.what() << endl;
    }
#endif
}

void testCreate02() {
#ifdef TEST_CREATE_02
    cout << "\nТЕСТ CREATE_02: Проверка генерации исключения THROW02" << endl;
    try {
        Instance dict = Create("Test", 101); // DICTMAXSIZE = 100
        cout << "ОШИБКА: Исключение не было сгенерировано" << endl;
    }
    catch (exception& e) {
        cout << "УСПЕХ: Перехвачено исключение: " << e.what() << endl;
    }
#endif
}

void testAddEntry03() {
#ifdef TEST_ADDENTRY_03
    cout << "\nТЕСТ ADDENTRY_03: Проверка генерации исключения THROW03" << endl;
    try {
        Instance dict = Create("Test", 2);
        Entry e1 = { 1, "First" };
        Entry e2 = { 2, "Second" };
        Entry e3 = { 3, "Third" };
        
        AddEntry(dict, e1);
        AddEntry(dict, e2);
        AddEntry(dict, e3); // Должно вызвать исключение
        cout << "ОШИБКА: Исключение не было сгенерировано" << endl;
    }
    catch (exception& e) {
        cout << "УСПЕХ: Перехвачено исключение: " << e.what() << endl;
    }
#endif
}

void testAddEntry04() {
#ifdef TEST_ADDENTRY_04
    cout << "\nТЕСТ ADDENTRY_04: Проверка генерации исключения THROW04" << endl;
    try {
        Instance dict = Create("Test", 5);
        Entry e1 = { 1, "First" };
        Entry e2 = { 1, "Second" }; // Тот же id
        
        AddEntry(dict, e1);
        AddEntry(dict, e2);
        cout << "ОШИБКА: Исключение не было сгенерировано" << endl;
    }
    catch (exception& e) {
        cout << "УСПЕХ: Перехвачено исключение: " << e.what() << endl;
    }
#endif
}

void testGetEntry05() {
#ifdef TEST_GETENTRY_05
    cout << "\nТЕСТ GETENTRY_05: Проверка генерации исключения THROW05" << endl;
    try {
        Instance dict = Create("Test", 5);
        Entry e = GetEntry(dict, 1); // Словарь пуст
        cout << "ОШИБКА: Исключение не было сгенерировано" << endl;
    }
    catch (exception& e) {
        cout << "УСПЕХ: Перехвачено исключение: " << e.what() << endl;
    }
#endif
}

void testGetEntry06() {
#ifdef TEST_GETENTRY_06
    cout << "\nТЕСТ GETENTRY_06: Проверка генерации исключения THROW06" << endl;
    try {
        Instance dict = Create("Test", 5);
        Entry e1 = { 1, "First" };
        AddEntry(dict, e1);
        DelEntry(dict, 2); // Несуществующий id
        cout << "ОШИБКА: Исключение не было сгенерировано" << endl;
    }
    catch (exception& e) {
        cout << "УСПЕХ: Перехвачено исключение: " << e.what() << endl;
    }
#endif
}

void testUpdEntry07() {
#ifdef TEST_UPDENTRY_07
    cout << "\nТЕСТ UPDENTRY_07: Проверка генерации исключения THROW07" << endl;
    try {
        Instance dict = Create("Test", 5);
        Entry e1 = { 1, "First" };
        Entry e2 = { 2, "Update" };
        AddEntry(dict, e1);
        UpdEntry(dict, 3, e2); // Несуществующий id
        cout << "ОШИБКА: Исключение не было сгенерировано" << endl;
    }
    catch (exception& e) {
        cout << "УСПЕХ: Перехвачено исключение: " << e.what() << endl;
    }
#endif
}

void testUpdEntry08() {
#ifdef TEST_UPDENTRY_08
    cout << "\nТЕСТ UPDENTRY_08: Проверка генерации исключения THROW08" << endl;
    try {
        Instance dict = Create("Test", 5);
        Entry e1 = { 1, "First" };
        Entry e2 = { 2, "Second" };
        Entry e3 = { 1, "Update" }; // Дублирующий id
        
        AddEntry(dict, e1);
        AddEntry(dict, e2);
        UpdEntry(dict, 2, e3);
        cout << "ОШИБКА: Исключение не было сгенерировано" << endl;
    }
    catch (exception& e) {
        cout << "УСПЕХ: Перехвачено исключение: " << e.what() << endl;
    }
#endif
}

void testDictionary() {
#ifdef TEST_DICTIONARY
    cout << "\nТЕСТ DICTIONARY: Демонстрация работы словарей" << endl;
    try {
        // Создание словаря студентов
        Instance students = Create("Студенты", 10);
        
        // Добавление студентов
        Entry s1 = { 1, "Иванов" };
        Entry s2 = { 2, "Петров" };
        Entry s3 = { 3, "Сидоров" };
        Entry s4 = { 4, "Козлов" };
        Entry s5 = { 5, "Смирнов" };
        Entry s6 = { 6, "Соколов" };
        Entry s7 = { 7, "Попов" };
        
        AddEntry(students, s1);
        AddEntry(students, s2);
        AddEntry(students, s3);
        AddEntry(students, s4);
        AddEntry(students, s5);
        AddEntry(students, s6);
        AddEntry(students, s7);
        
        // Создание словаря преподавателей
        Instance teachers = Create("Преподаватели", 10);
        
        // Добавление преподавателей
        Entry t1 = { 1, "Александров" };
        Entry t2 = { 2, "Борисов" };
        Entry t3 = { 3, "Васильев" };
        Entry t4 = { 4, "Григорьев" };
        Entry t5 = { 5, "Дмитриев" };
        Entry t6 = { 6, "Евгеньев" };
        Entry t7 = { 7, "Жуков" };
        
        AddEntry(teachers, t1);
        AddEntry(teachers, t2);
        AddEntry(teachers, t3);
        AddEntry(teachers, t4);
        AddEntry(teachers, t5);
        AddEntry(teachers, t6);
        AddEntry(teachers, t7);
        
        // Вывод содержимого словарей
        cout << "\nСодержимое словарей:" << endl;
        Print(students);
        cout << endl;
        Print(teachers);
        
        // Очистка памяти
        Delete(students);
        Delete(teachers);
        
        cout << "\nУСПЕХ: Тест успешно завершен" << endl;
    }
    catch (exception& e) {
        cout << "ОШИБКА: " << e.what() << endl;
    }
#endif
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    cout << "=== НАЧАЛО ТЕСТИРОВАНИЯ ===" << endl;
    
    testCreate01();
    testCreate02();
    testAddEntry03();
    testAddEntry04();
    testGetEntry05();
    testGetEntry06();
    testUpdEntry07();
    testUpdEntry08();
    testDictionary();
    
    cout << "\n=== ТЕСТИРОВАНИЕ ЗАВЕРШЕНО ===" << endl;
    
    return 0;
} 