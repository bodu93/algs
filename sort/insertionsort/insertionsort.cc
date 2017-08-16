#include "insertionsort.h"

void swap_(int *p, int *q) {
	int t = *p;
	*p = *q;
	*q = t;
}

// A[p,r)
// |-------|----------|
// ^       ^^
// 0       ij
// A[0, j) are sorted
// we just insert A[j] to A[0, j] to expand the length of A[0, n)
void insertionsort_(int *A, size_t p, size_t r) {
	for (size_t i = p + 1; i != r; ++i) {
		for (size_t j = i; j > p; --j) {
			if (A[j] < A[j - 1]) {
				swap_(A + j, A + j - 1);
			} else {
				break;
			}
		}
	}
}

// not swap directly! we just assignment
void insertionsort_improved(int *A, size_t p, size_t r) {
	for (size_t i = p + 1; i != r; ++i) {
		int beInserted = A[i];
		size_t j = i;
		for (; j > p; --j) {
			if (beInserted < A[j - 1]) {
				A[j] = A[j - 1];
			} else {
				break;
			}
		}
		A[j] = beInserted;
	}
}
