#include <iostream>
#include <string>
#include "hash_map.h"
using namespace std;


int main() {
    hash_map* telefones = hash_map_create(8);
    hash_map_insert(telefones, 291112233, "FIO1");
    hash_map_insert(telefones, 292223344, "FIO2");
    hash_map_insert(telefones, 291234567, "FIO3");
    hash_map_insert(telefones, 292345678, "FIO4");
    hash_map_insert(telefones, 331232323, "FIO5");

    cout << hash_map_at(telefones, 331232323) << endl;

    hash_map_display(telefones);
    return 0;
}