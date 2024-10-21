#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <stdbool.h>
#include "hash_function.h"

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node** table;
    size_t size;
    size_t count;
    hash_function hash_func;
} HashTable;

HashTable* create_hash_table(size_t initial_size, hash_function hash_func);
void insert(HashTable* ht, int key, int value);
bool search(HashTable* ht, int key, int* value);
bool delete(HashTable* ht, int key);
void destroy_hash_table(HashTable* ht);
void print_hash_table(HashTable* ht);

#endif 