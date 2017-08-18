#include "partition.h"
#include "../include/swp.h"
#include "../include/utility.h"
#include <vector>

void quicksort(int *A, size_t p, size_t q) {
	if (p < q) {
		//size_t mid = lomuto_partition(A, p, q);
		size_t mid = hoare_partition(A, p, q);
		quicksort(A, p, mid);
		quicksort(A, mid + 1, q);
	}
}

// A[lo, hi)
void triple_segmentation(int *A, size_t lo, size_t hi) {
	if (lo >= hi) return;
	
	size_t lt = lo;
	size_t i = lo + 1;
	size_t gt = hi;
	int v = A[lo];
	while (i != gt) {
		if (A[i] < v) {
			swap_(A + i, A + lt);
			++i;
			++lt;
		} else if (A[i] > v) {
			--gt;
			swap_(A + i, A + gt);
		} else {
			++i;
		}
	}
		
	triple_segmentation(A, lo, lt);
	triple_segmentation(A, gt, hi);
}

void qsort_(int *A, size_t n) {
	//quicksort(A, 0, n);
	triple_segmentation(A, 0, n);
}
