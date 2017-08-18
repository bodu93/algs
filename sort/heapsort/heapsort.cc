#include "heapsort.h"
#include "../include/swp.h"

// rank begin with 0
size_t parent(size_t k) {
	if (k == 0) return 0;
	return (k - 1) / 2;
}

size_t lchild(size_t k) {
	return 2 * k + 1;
}

size_t rchild(size_t k) {
	return 2 * (k + 1);
}

void sink(int *A, size_t k, size_t n) {
	while (lchild(k) < n) {
		size_t j = lchild(k);
		if (j < n - 1 && A[j] <= A[j + 1]) j++;
		if (A[k] > A[j]) break;
		swap_(A + k, A + j);
		k = j;
	}
}

void heapsort(int *A, size_t n) {
	if (n == 0) return;

	for (size_t k = parent(n - 1); ; --k) {
		sink(A, k, n);
		if (k == 0) break;
	}

	while (n > 0) {
		--n;
		swap_(A, A + n);
		sink(A, 0, n);
	}
}
