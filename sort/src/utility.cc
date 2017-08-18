#include "../include/utility.h"

bool isSorted(int *A, size_t n) {
	bool result = true;
	if (n <= 1) return result;

	for (size_t i = 0; i != n - 1; ++i) {
		if (A[i] > A[i + 1]) {
			result = false;
			break;
		}
	}

	return result;
}
