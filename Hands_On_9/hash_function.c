#include "hash_function.h"

size_t multiplication_division_hash(int key, size_t table_size) {
    const double A = 0.6180339887; //helps distribute hash values more uniformly across the table: (√5 - 1) / 2
    double product = key * A;
    double fractional_part = product - (int)product;
    return (size_t)(table_size * fractional_part);
}