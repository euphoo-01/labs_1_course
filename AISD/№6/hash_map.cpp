#include "hash_map.h"

#include <iostream>

typedef struct _hash_map_entry_ {
    int key;
    std::string value;
    _hash_map_entry_ *next;
} hash_map_entry;

typedef struct _hash_map_ {
    int size;
    hash_map_entry **table;
} hash_map;

int hash (int key, int size) {
    return ((key >> 16)^ key) % size;
}

void hash_map_insert(hash_map *map, int key, std::string value) {
    int idx = hash(key, map->size);

    if (map->table[idx] == nullptr) {
        map->table[idx] = new hash_map_entry();
        map->table[idx]->key = key;
        map->table[idx]->value = value;
        map->table[idx]->next = nullptr;
    }
    else {
        hash_map_entry *new_entry = new hash_map_entry();
        new_entry->key = key;
        new_entry->value = value;
        new_entry->next = map->table[idx];
        map->table[idx] = new_entry;
    }
}
void hash_map_del(hash_map *map, int key) {
    int idx = hash(key, map->size);

    if (map->table[idx] != nullptr) {
        hash_map_entry *entry = map->table[idx];
        while (entry != nullptr) {
            if (entry->key == key) {
                hash_map_entry *next = entry->next;
                delete entry;
                map->table[idx] = next;
                return;
            }
            entry = entry->next;
        }
    }
}

void hash_map_display(hash_map *map) {
    for (int i = 0; i < map->size; i++) {
        hash_map_entry *entry = map->table[i];
        while (entry != nullptr) {
            hash_map_entry *next = entry->next;
            std::cout << entry->key << " " << entry->value << "\n";
            entry = next;
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

    return "Р­Р»РµРјРµРЅС‚ РЅРµ РЅР°Р№РґРµРЅ";
}

hash_map *hash_map_create(int size) {
    hash_map *map = new hash_map();
    map->size = size;
    map->table = new hash_map_entry *[size];
    for (int i = 0; i < size; i++) {
        map->table[i] = nullptr;
    }
    return map;
}
void hash_map_free(hash_map *map) {
    int size = map->size;
    for (int i = 0; i < size; i++) {
        hash_map_entry *entry = map->table[i];
            while (map->table[i] != nullptr) {
                hash_map_entry *next = map->table[i]->next;
                delete entry;
                entry = next;
            }
    }
}