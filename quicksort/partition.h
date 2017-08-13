#ifndef PARTITION_H
#define PARTITION_H

#include <stddef.h>

// A[p, r)
size_t partition(int *A, size_t p, size_t r);

size_t hoare_partition(int *A, size_t p, size_t r);

#endif
