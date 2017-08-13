#include "selectionsort.h"

void swap_(int *p, int *q) {
	int t = *p;
	*p = *q;
	*q = t;
}

void selectionsort_(int *A, size_t p, size_t r) {
	for (size_t i = p; i != r; ++i) {
		int min_elem_rank = i;
		for (size_t j = i; j != r; ++j) {
			if (A[j] < A[min_elem_rank]) {
				min_elem_rank = j;
			}
		}
		swap_(A + i, A + min_elem_rank);
	}
}

void selectionsort(int *A, size_t n) {
	selectionsort_(A, 0, n);
}
