#include "partition.h"
#include <iostream>

void quicksort(int *A, size_t p, size_t q) {
	if (p < q) {
		size_t mid = partition(A, p, q);
		quicksort(A, p, mid);
		quicksort(A, mid + 1, q);
	}
}

void qsort_(int *A, size_t n) {
	quicksort(A, 0, n);
}

int main() {
	int a[] = { 5, 4, 3, 2, 1 };

	qsort_(a, sizeof(a) / sizeof(int));

	for (auto i : a) 
		std::cout << i << std::endl;

	return 0;
}
