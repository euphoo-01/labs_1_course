#include "hash_map.h"
#include <iostream>

typedef struct _hash_map_entry_ {
    int key;
    std::string value;
    _hash_map_entry_ *next;
    _hash_map_entry_ *prev;
} hash_map_entry;

typedef struct _hash_map_ {
    int size;
    hash_map_entry **table;
    int busy_cells;
} hash_map;

int hash (int key, int size) {
    return key % size;
}

void hash_map_resize(hash_map& map) {
    hash_map* new_map = hash_map_create((int)(map.size * 1.5));

    for (int i = 0; i < map.size; i++) {
        hash_map_entry* entry = map.table[i];
        while (entry != nullptr) {
            hash_map_insert(new_map, entry->key, entry->value);
            entry = entry->next;
        }
    }

    hash_map_free(&map);
    map = *new_map;
}

void hash_map_insert(hash_map *map, int key, std::string value) {
    int idx = hash(key, map->size);

    if (map->table[idx] == nullptr) {
        map->table[idx] = new hash_map_entry();
        map->table[idx]->key = key;
        map->table[idx]->value = value;
        map->table[idx]->next = nullptr;
        map->table[idx]->prev = nullptr;
        map->busy_cells++;
    }
    else {
        hash_map_entry *new_entry = new hash_map_entry();
        new_entry->key = key;
        new_entry->value = value;
        new_entry->next = map->table[idx];
        map->table[idx]->prev = new_entry;
        new_entry->prev = nullptr;
        map->table[idx] = new_entry;
        map->busy_cells++;
    }

    if (map->busy_cells == map->size) { // В случае переполнения
        hash_map_resize(*map);
    }
}

void hash_map_del(hash_map *map, int key) {
    int idx = hash(key, map->size);

    if (map->table[idx]) {
        hash_map_entry *entry = map->table[idx];
        while (entry->key != key) {
            entry = entry->next;
        }
            if (entry->prev && entry->next) {
                entry->prev->next = entry->next;
                entry->next->prev = entry->prev;
                delete entry;
                map->busy_cells--;
            }
            if (entry->next && !entry->prev) {
                entry->next->prev = nullptr;
                map->table[idx] = entry->next;
                map->busy_cells--;
                delete entry;
            }
            if (entry->prev && !entry->next) {
                entry->prev->next = nullptr;
                map->table[idx] = entry->prev;
                map->busy_cells--;
                delete entry;
            }
    }
}

void hash_map_display(hash_map *map) {
    for (int i = 0; i < map->size; i++) {
        hash_map_entry *entry = map->table[i];
        while (entry) {
            hash_map_entry *next = entry->next;
            std::cout << i << ". " << entry->key << " " << entry->value << "\t";
            entry = next;
        }
        if (!map->table[i]) {
            std::cout << "Пусто" << "\n";
        }
        else {
            std::cout << "\n";
        }
    }
}

std::string hash_map_at(hash_map *map, int key) {
    int idx = hash(key, map->size);

    if (map->table[idx] != nullptr) {
        hash_map_entry *entry = map->table[idx];
        while (entry != nullptr) {
            if (entry->key == key) {
                return entry->value;
            }
            entry = entry->next;
        }
    }

    return "Элемент не найден";
}

hash_map *hash_map_create(int size) {
    hash_map *map = new hash_map();
    map->size = size;
    map->table = new hash_map_entry*[size];
    for (int i = 0; i < size; i++) {
        map->table[i] = nullptr;
    }
    map->busy_cells = 0;
    return map;
}

void hash_map_free(hash_map *map) {
    for (int i = 0; i < map->size; ++i) {
        hash_map_entry *entry = map->table[i];
        while (entry != nullptr) {
            hash_map_entry *next = entry->next;
            delete entry;
            entry = next;
        }
    }
    delete[] map->table;
}