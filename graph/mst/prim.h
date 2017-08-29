#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <stddef.h>
#include <limits>
#include "graph.h"

struct vertex {
	size_t to{0};
	size_t parent{static_cast<size_t>(-1)};	// -1 for empty
	double key{std::numeric_limits<double>::max()};

	bool operator<(const vertex &other) const {
		return key < other.key;
	}

	bool operator<=(const vertex &other) const {
		return key <= other.key;
	}

	bool operator==(const vertex &other) const {
		return key == other.key;
	}
};

class prim {
public:
	explicit prim(graph g);

	std::vector<size_t> mst(size_t r);

private:
	graph g_;
	
	std::vector<vertex> nodes_;
	std::vector<bool> inq_;
};

#endif // PRIM_H
