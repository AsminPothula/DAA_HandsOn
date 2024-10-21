#include <stdio.h>
#include "hash_table.h"

int main() {
    HashTable* ht = create_hash_table(10, multiplication_division_hash);

    printf("Inserting keys: 5, 2, 15, 7, 20\n");
    insert(ht, 5, 500);
    insert(ht, 2, 200);
    insert(ht, 15, 1500);
    insert(ht, 7, 700);
    insert(ht, 20, 2000);

    print_hash_table(ht);

    printf("\nDeleting key: 2\n");
    delete(ht, 2);
    print_hash_table(ht);

    printf("\nInserting key: 25\n");
    insert(ht, 25, 2500);
    print_hash_table(ht);

    int value;
    if (search(ht, 15, &value)) {
        printf("\nValue for key 15: %d\n", value);
    }

    printf("\nDeleting keys: 5, 15\n");
    delete(ht, 5);
    delete(ht, 15);
    print_hash_table(ht);

    destroy_hash_table(ht);

    return 0;
}