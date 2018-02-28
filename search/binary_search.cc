#include <vector>
#include <iterator>
#include <string.h> // atoi

#include <iostream>

// do binary search in range [first,
// last)
// if not found, return last
template<typename RandomIterator>
RandomIterator binary_search(
		RandomIterator first,
		RandomIterator last,
		const typename std::iterator_traits<RandomIterator>::value_type& key) {
	RandomIterator result = last;
	while (first < last) {
		RandomIterator mid = first + (last - first) / 2;
		if (*mid == key) {
			result = mid;
			break;
		} else if (key > *mid) {
			first = mid + 1;
		} else { // key < *mid
			last = mid;
		}
	}

	return result;
}

int main(int argc, char* argv[]) {
	int key = atoi(argv[1]);
	std::vector<int> vec {
		1, 3, 5, 7
	};

	auto it = ::binary_search(vec.begin(), vec.end(), key);
	if (it == vec.end()) {
		std::cout << "not found" << std::endl;
	} else {
		std::cout << "founded" << std::endl;
	}

	return 0;
}
