#include "stdafx.h"

namespace Dictionary {
    Instance Create(char name[DICTNAMEMAXSIZE], int size) {
        if (strlen(name) > DICTNAMEMAXSIZE)
            throw std::exception(THROW01);
        if (size > DICTMAXSIZE || size <= 0)
            throw std::exception(THROW02);

        Instance newInstance;
        strncpy_s(newInstance.name, name, DICTNAMEMAXSIZE);
        newInstance.maxsize = size;
        newInstance.size = 0;
        newInstance.dictionary = new Entry[size];

        return newInstance;
    }

    void AddEntry(Instance& inst, Entry ed) {
        if (inst.size >= inst.maxsize)
            throw std::exception(THROW03);

        // Проверка на дублирование идентификатора
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i].id == ed.id)
                throw std::exception(THROW04);
        }

        inst.dictionary[inst.size] = ed;
        inst.size++;
    }

    void DelEntry(Instance& inst, int id) {
        int foundIndex = -1;

        // Поиск элемента с указанным id
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i].id == id) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex == -1)
            throw std::exception(THROW06);

        // Сдвиг элементов для удаления
        for (int i = foundIndex; i < inst.size - 1; i++) {
            inst.dictionary[i] = inst.dictionary[i + 1];
        }

        inst.size--;
    }

    void UpdEntry(Instance& inst, int id, Entry new_ed) {
        int foundIndex = -1;

        // Поиск элемента с указанным id
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i].id == id) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex == -1)
            throw std::exception(THROW07);

        // Проверка на дублирование id (если новый id отличается от обновляемого)
        if (new_ed.id != id) {
            for (int i = 0; i < inst.size; i++) {
                if (i != foundIndex && inst.dictionary[i].id == new_ed.id)
                    throw std::exception(THROW08);
            }
        }

        inst.dictionary[foundIndex] = new_ed;
    }

    Entry GetEntry(Instance inst, int id) {
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i].id == id) {
                return inst.dictionary[i];
            }
        }

        throw std::exception(THROW05);
    }

    void Print(Instance d) {
        std::cout << "----- " << d.name << " -----" << std::endl;

        for (int i = 0; i < d.size; i++) {
            std::cout << d.dictionary[i].name << std::endl;
        }
    }

    void Delete(Instance& d) {
        delete[] d.dictionary;
        d.size = 0;
        d.maxsize = 0;
    }
}