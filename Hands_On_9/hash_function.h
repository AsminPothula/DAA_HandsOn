#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

#include <stddef.h>

typedef size_t (*hash_function)(int key, size_t table_size);
size_t multiplication_division_hash(int key, size_t table_size);

#endif 