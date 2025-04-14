#include "stdafx.h"
#include <windows.h>

using namespace Dictionary;
using namespace std;

void demonstrateDictionary() {
    try {
        char dictName[DICTNAMEMAXSIZE] = "TestDict";
        cout << "Создание словаря '" << dictName << "'" << endl;
        Instance dict = Create(dictName, 5);

        cout << "\nДобавление элементов в словарь:" << endl;
        Entry e1 = { 1, "Первый" };
        Entry e2 = { 2, "Второй" };
        Entry e3 = { 3, "Третий" };

        AddEntry(dict, e1);
        cout << "Добавлен элемент с id=" << e1.id << ", name=" << e1.name << endl;

        AddEntry(dict, e2);
        cout << "Добавлен элемент с id=" << e2.id << ", name=" << e2.name << endl;

        AddEntry(dict, e3);
        cout << "Добавлен элемент с id=" << e3.id << ", name=" << e3.name << endl;

        cout << "\nВывод содержимого словаря:" << endl;
        Print(dict);
        system("pause");

        cout << "\nПолучение элемента с id=2:" << endl;
        Entry found = GetEntry(dict, 2);
        cout << "Найден элемент: id=" << found.id << ", name=" << found.name << endl;
        system("pause");

        cout << "\nОбновление элемента с id=2:" << endl;
        Entry updated = { 2, "Обновленный" };
        UpdEntry(dict, 2, updated);
        cout << "Элемент обновлен" << endl;

        cout << "\nВывод содержимого словаря после обновления:" << endl;
        Print(dict);
        system("pause");

        cout << "\nУдаление элемента с id=1:" << endl;
        DelEntry(dict, 1);
        cout << "Элемент удален" << endl;

        cout << "\nВывод содержимого словаря после удаления:" << endl;
        Print(dict);
        system("pause");

        cout << "\nОсвобождение памяти словаря" << endl;
        Delete(dict);
        cout << "Память освобождена" << endl;
        system("pause");
    }
    catch (std::exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

void demonstrateErrors() {
    cout << "\n--- Демонстрация обработки ошибок ---\n" << endl;

    try {
        cout << "Попытка создать словарь со слишком длинным именем:" << endl;
        char longName[50] = "ThisNameIsTooLongForDictionaryNameLimitTest";
        Instance dict = Create(longName, 10);
    }
    catch (std::exception& e) {
        cout << "Поймано исключение: " << e.what() << endl;
    }
    system("pause");

    try {
        cout << "\nПопытка создать словарь с неверным размером:" << endl;
        char name[DICTNAMEMAXSIZE] = "Dict";
        Instance dict = Create(name, DICTMAXSIZE + 10);
    }
    catch (std::exception& e) {
        cout << "Поймано исключение: " << e.what() << endl;
    }
    system("pause");

    try {
        cout << "\nСоздание корректного словаря для тестирования ошибок:" << endl;
        char name[DICTNAMEMAXSIZE] = "ErrorTest";
        Instance dict = Create(name, 2);

        Entry e1 = { 1, "Первый" };
        Entry e2 = { 2, "Второй" };

        AddEntry(dict, e1);
        AddEntry(dict, e2);
        cout << "Добавлены два элемента в словарь размером 2" << endl;

        try {
            cout << "\nПопытка добавить элемент с существующим id:" << endl;
            Entry duplicate = { 1, "Дубликат" };
            AddEntry(dict, duplicate);
        }
        catch (std::exception& e) {
            cout << "Поймано исключение: " << e.what() << endl;
        }
        system("pause");


        try {
            cout << "\nПопытка добавить элемент в полный словарь:" << endl;
            Entry overflow = { 3, "Переполнение" };
            AddEntry(dict, overflow);
        }
        catch (std::exception& e) {
            cout << "Поймано исключение: " << e.what() << endl;
        }
        system("pause");

        try {
            cout << "\nПопытка получить несуществующий элемент:" << endl;
            Entry notFound = GetEntry(dict, 99);
        }
        catch (std::exception& e) {
            cout << "Поймано исключение: " << e.what() << endl;
        }
        system("pause");

        try {
            cout << "\nПопытка удалить несуществующий элемент:" << endl;
            DelEntry(dict, 99);
        }
        catch (std::exception& e) {
            cout << "Поймано исключение: " << e.what() << endl;
        }
        system("pause");

        try {
            cout << "\nПопытка обновить несуществующий элемент:" << endl;
            Entry updNotFound = { 99, "Обновленный" };
            UpdEntry(dict, 99, updNotFound);
        }
        catch (std::exception& e) {
            cout << "Поймано исключение: " << e.what() << endl;
        }
        system("pause");

        try {
            cout << "\nПопытка обновить элемент с созданием дубликата id:" << endl;
            Entry updDuplicate = { 2, "Обновление с id=2" };
            UpdEntry(dict, 1, updDuplicate);
        }
        catch (std::exception& e) {
            cout << "Поймано исключение: " << e.what() << endl;
        }
        system("pause");

        Delete(dict);
    }
    catch (std::exception& e) {
        cout << "Непредвиденная ошибка: " << e.what() << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=== Демонстрация работы словаря ===" << endl;
    demonstrateDictionary();

    demonstrateErrors();

    return 0;
}