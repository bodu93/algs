#ifndef MAXPQ_H
#define MAXPQ_H

#include <vector>

template <typename T>
class MaxPQ {
	typedef typename std::vector<T>::size_type size_type;
	typedef T Key;

	// reserve rank 0 for simplification.
	std::vector<T> pq_;
	size_type size_;

	size_type parent(size_t k) {
		return k / 2;
	}

	void swap_(size_type p, size_type q) {
		Key t = pq_[p];
		pq_[p] = pq_[q];
		pq_[q] = t;
	}

	bool less_(size_type l, size_type r) {
		return pq_[l] <= pq_[r];
	}

	void swim(size_type k) {
		while (k > 1 && less_(k / 2, k)) {
			swap_(k / 2, k);
			k = k / 2;
		}
	}

	void sink(size_type k) {
		while (2 * k <= size_) {
			size_type j = 2 * k;
			if (j < size_ && less_(j, j + 1)) j++;
			if (!less_(k, j)) break;
			swap_(k, j);
			k = j;
		}
	}
public:
	MaxPQ(): pq_(1), size_(0) { }

	void insert(const Key& v) {
		pq_.push_back(v);
		++size_;
		swim(size_);
	}

	Key delMax() {
		Key m = Key();

		if (!empty()) {
			m = pq_[1];
			swap_(1, size_--);
			sink(1);
		}
		return m;
	}

	bool empty() const {
		return size_ == 0;
	}

	int size() const {
		return size_;
	}
};

#endif //MAXPQ_H
