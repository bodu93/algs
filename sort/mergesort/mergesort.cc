#include "mergesort.h"
#include "../include/swp.h"

size_t min_(size_t l, size_t r) {
	return l <= r ? l : r;
}

// A[lo, mid), A[mid, hi)
void merge(int *A, size_t lo, size_t mid, size_t hi, int * aux) {
	size_t i = lo;
	size_t j = mid;

	// copy A[lo, hi) to aux[0, hi - lo)
	for (size_t k = lo; k != hi; ++k) {
		aux[k] = A[k];
	}

	// sort A[lo, hi)
	for (size_t k = lo; k != hi; ++k) {
		if (i >= mid) A[k] = aux[j++];
		else if (j >= hi) A[k] = aux[i++];
        else {
            // opitimized for using cmov**
            bool bresult = aux[i] <= aux[j];
            int min = bresult ? aux[i] : aux[j];
            size_t *minrank = bresult ? &i : &j;
            ++(*minrank);
            A[k] = min;
        }
		//else if (aux[i] <= aux[j]) A[k] = aux[i++];
		//else A[k] = aux[j++];
	}
}

// A[lo, hi)
void mergesort_(int *A, size_t lo, size_t hi, int* aux) {
	if (lo + 1 < hi) {
		size_t mid = lo + (hi - lo) / 2;
		mergesort_(A, lo, mid, aux);
		mergesort_(A, mid, hi, aux);
		merge(A, lo, mid, hi, aux);
	}
}

// bu: bottom to up
void mergesort_bu(int *A, size_t lo, size_t hi) {
	size_t N = hi - lo;
	int *aux = new int[N];

	for (size_t sz = 1; sz < N; sz = sz + sz) {
		for (size_t lo = 0; lo < N - sz; lo += sz + sz) {
			merge(A, lo, lo + sz, min_(N, lo + sz + sz), aux);
		}
	}

	delete [] aux;
}

void mergesort(int *A, size_t n) {
	mergesort_bu(A, 0, n);
	//int *aux = new int[n];
	//mergesort_(A, 0, n, aux);
	//delete [] aux;
}
