#ifndef MINPQ_H
#define MINPQ_H

#include <vector>
// for size_t
#include <stddef.h>
// for std::swap
#include <utility>

template <typename T>
class MinPQ {
public:
	MinPQ()
		:pq_(1)
		 ,size_(0)
	{ }

	void insert(const T &key) {
		pq_.push_back(key);
		++size_;
		swim(size_);
	}

	T delMin() {
		T key = T();

			if (!empty()) {
				key = pq_[1];
				std::swap(pq_[1], pq_[size_--]);
				sink(1);
			}

			return key;
		}

		T min() const {
			return pq_[1];
		}

		// rank begin with 0
		void decreaseKey(size_t rank, const T &newKey) {
			if (empty() || rank + 1 > size_ || pq_[rank + 1] <= newKey) return;

		pq_[rank + 1] = newKey;

		swim(rank + 1);
		sink(rank + 1);
	}

	size_t findKey(const T &f, bool (*equals)(const T &, const T &)) const {
		size_t result = static_cast<size_t>(-1);
		
		for (size_t i = 0; i != size_; ++i) {
			if (equals(f, pq_[i + 1])) {
				result = i;
				break;
			}
		}

		return result;
	}

	bool empty() const {
		return size_ == 0;
	}
	
private:
	std::vector<T> pq_;
	size_t size_;

	size_t parent(size_t k) const {
		return k / 2;
	}

	size_t lchild(size_t k) const {
		return 2 * k;
	}

	size_t rchild(size_t k) const {
		return 2 * k + 1;
	}

	void swim(size_t k) {
		while (k > 1 && pq_[k] < pq_[parent(k)]) {
			using std::swap;
			swap(pq_[parent(k)], pq_[k]);
			k = parent(k);
		}
	}

	void sink(size_t k) {
		while (lchild(k) <= size_) {
			size_t j = 2 * k;
			if (j < size_ && pq_[j + 1] < pq_[j]) ++j;
			if (pq_[k] <= pq_[j]) break;

			using std::swap;
			swap(pq_[k], pq_[j]);
			k = j;
		}
	}
};

#endif // MINPQ_H
