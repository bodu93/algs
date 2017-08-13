#include "partition.h"
#include <iostream>
#include <vector>

void quicksort(int *A, size_t p, size_t q) {
	if (p < q) {
		//size_t mid = lomuto_partition(A, p, q);
		size_t mid = hoare_partition(A, p, q);
		quicksort(A, p, mid);
		quicksort(A, mid + 1, q);
	}
}

void qsort_(int *A, size_t n) {
	quicksort(A, 0, n);
}
