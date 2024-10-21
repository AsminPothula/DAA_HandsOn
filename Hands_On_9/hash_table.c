#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>

static void resize(HashTable* ht, size_t new_size);
static Node* create_node(int key, int value);

HashTable* create_hash_table(size_t initial_size, hash_function hash_func) {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->size = initial_size;
    ht->count = 0;
    ht->hash_func = hash_func;
    ht->table = calloc(initial_size, sizeof(Node*));
    return ht;
}

void insert(HashTable* ht, int key, int value) {
    if (ht->count >= ht->size) {
        resize(ht, ht->size * 2); //checks if the table is full and doubles the size if needed
    }

    size_t index = ht->hash_func(key, ht->size);
    Node* new_node = create_node(key, value);

    if (ht->table[index] == NULL) {
        ht->table[index] = new_node;
    } else {
        new_node->next = ht->table[index];
        ht->table[index]->prev = new_node;
        ht->table[index] = new_node;
    }

    ht->count++;
}

bool search(HashTable* ht, int key, int* value) {
    size_t index = ht->hash_func(key, ht->size);
    Node* current = ht->table[index];

    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return true;
        }
        current = current->next;
    }

    return false;
}

bool delete(HashTable* ht, int key) {
    size_t index = ht->hash_func(key, ht->size);
    Node* current = ht->table[index];

    while (current != NULL) {
        if (current->key == key) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                ht->table[index] = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            ht->count--;

            if (ht->count <= ht->size / 4 && ht->size > 1) {
                resize(ht, ht->size / 2); // checks if the table is 1/4 full or less and halves the size if needed
            }

            return true;
        }
        current = current->next;
    }

    return false;
}

void destroy_hash_table(HashTable* ht) {
    for (size_t i = 0; i < ht->size; i++) {
        Node* current = ht->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

static void resize(HashTable* ht, size_t new_size) { // creates a new table of the new size and re-hashes all existing elements into it
    Node** new_table = calloc(new_size, sizeof(Node*));
    
    for (size_t i = 0; i < ht->size; i++) {
        Node* current = ht->table[i];
        while (current != NULL) {
            Node* next = current->next;
            size_t new_index = ht->hash_func(current->key, new_size);
            
            current->prev = NULL;
            current->next = new_table[new_index];
            if (new_table[new_index] != NULL) {
                new_table[new_index]->prev = current;
            }
            new_table[new_index] = current;
            
            current = next;
        }
    }

    free(ht->table);
    ht->table = new_table;
    ht->size = new_size;
}

static Node* create_node(int key, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void print_hash_table(HashTable* ht) {
    printf("Hash Table Contents:\n");
    for (size_t i = 0; i < ht->size; i++) {
        printf("Bucket %zu: ", i);
        Node* current = ht->table[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
    printf("Total items: %zu\n", ht->count);
}