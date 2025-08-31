#ifndef HASH_MAP_H
#define HASH_MAP_H
#include <string>

typedef struct _hash_map_entry_ hash_map_entry;

typedef struct _hash_map_ hash_map;

void hash_map_insert(hash_map*, int, std::string);
void hash_map_del(hash_map*, int);
void hash_map_display(hash_map*);
void hash_map_resize(hash_map&);
std::string hash_map_at(hash_map*, int);
int hash (int, int);


hash_map *hash_map_create(int);
void hash_map_free(hash_map*);

#endif //HASH_MAP_H
