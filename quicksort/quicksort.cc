#include "partition.h"
#include <iostream>
#include <vector>

void quicksort(int *A, size_t p, size_t q) {
	if (p < q) {
		//size_t mid = partition(A, p, q);
		size_t mid = hoare_partition(A, p, q);
		quicksort(A, p, mid);
		quicksort(A, mid + 1, q);
	}
}

void qsort_(int *A, size_t n) {
	quicksort(A, 0, n);
}

void print(const std::vector<int> &vec) {
	for (auto i : vec)
		std::cout << std::endl << i << std::endl;
}

void test(std::vector<int> &vec) {
	qsort_(&vec[0], vec.size());
	print(vec);
}


int main() {
	std::vector<std::vector<int>> vecs {
		{ 1, 2, 3, 4, 5 },
		{ 9, -1, 0, 99, -4, 42 },
		{ 0, -9, 1, 92, 3, 9, 34, 41, 84 },
		{ 91, 19, 82, 29, 21, 11, -999 }
	};

	for (auto vec : vecs) {
		test(vec);
	}

	return 0;
}
