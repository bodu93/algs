#ifndef UNION_FIND_SET_H
#define UNION_FIND_SET_H

#include <vector>
#include <stddef.h>

// union-find set
class ufset {
public:
	// MAKE-SET
	explicit ufset(size_t n);

	bool connected(int p, int q) const;

	// FIND-SET
	int find(int m) const;

	// UNION
	void doUnion(int p, int q);

	size_t count() const;

private:
	std::vector<int> ids_;
	std::vector<int> sz_;
	size_t count_;
};

#endif // UNION_FIND_SET_H
