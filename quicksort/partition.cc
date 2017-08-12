#include "partition.h"

void swap_(int *p, int *q) {
	int t = *p;
	*p = *q;
	*q = t;
}

// A[p, r)
// [x][...i][i+1...j]
size_t partition(int *A, size_t p, size_t r) {
	if (r <= p) return p;

	int middle = A[p];
	size_t i = p;
	for (size_t j = p + 1; j != r; ++j) {
		if (A[j] <= middle) {
			++i;
			swap_(A + j, A + i);	
		}
	}
	swap_(A + i, A + p);
	
	return i;
}
