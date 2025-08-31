#include <iostream>
#include <string>
#include <ctime>
#include "hash_map.h"
#include <chrono>
using namespace std;

void access_test();

int main() {
    auto telefones = hash_map_create(5);
    int choice;
    while (true) {
        cout << "1 - Вставить\n2 - Удалить\n3 - Поиск\n4 - Тест времени доступа\n5 - Отображение\n6 - Выход\nВаш выбор: "; cin >> choice;
        switch (choice) {
            case 1: {
                int key;
                string value;
                cout << "Введите номер телефона: "; cin >> key;
                cout << "Введите ФИО: ";
                std::cin.ignore(9999, '\n');
                getline(cin, value);
                hash_map_insert(telefones, key, value);
                break;
            }
            case 2: {
                int key;
                cout << "Введите номер телефона: "; cin >> key;
                hash_map_del(telefones, key);
                break;
            }
            case 3: {
                int key;
                cout << "Введите номер телефона: "; cin >> key;
                auto found = hash_map_at(telefones, key);
                cout << "Найденный элемент: " << found << endl;
                break;
            }
            case 4: {
                access_test();
                break;
            }
            case 5: {
                hash_map_display(telefones);
                break;
            }
            case 6: {
                return 0;
                break;
            }
        }

    }



    return 0;
}

void access_test() {
    auto access_test1 = hash_map_create(16);
    auto access_test2 = hash_map_create(128);

    srand(time(NULL));
    // Хеш-таблица на 16
    int savedKey;
    for (int i = 0; i < 16; i++) {
        int key = rand();
        int value = rand() % 32;
        hash_map_insert(access_test1, key, to_string(value));
        if (i == 8) {
            savedKey = key;
        }
    }
    auto start = chrono::high_resolution_clock::now();
    auto found_element = hash_map_at(access_test1, savedKey);
    cout << "\n" << found_element << endl;
    auto end = chrono::high_resolution_clock::now();
    hash_map_free(access_test1);
    chrono::duration<double, micro> elapsed = end - start;
    cout << "Время доступа(16): " << elapsed;

    // Хеш-таблица на 512
    int savedKey2;
    for (int i = 0; i < 512; i++) {
        int key = rand();
        int value = rand() % 512;
        hash_map_insert(access_test2, key, to_string(value));
        if (i == 256) {
            savedKey2 = key;
        }
    }
    start = chrono::high_resolution_clock::now();
    found_element = hash_map_at(access_test2, savedKey2);
    cout << endl << found_element << endl;
    end = chrono::high_resolution_clock::now();
    hash_map_free(access_test2);
    elapsed = end - start;
    cout << "Время доступа(512): " << elapsed << endl;

}