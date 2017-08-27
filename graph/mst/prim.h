#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <stddef.h>
#include "graph.h"

struct vertex {
	size_t to{0};
	size_t parent{-1};	// -1 for empty
	double key{0xffff}; // suppose 0xffff for positive infinity

	bool operator<(const edge &other) const {
		return key < other.key;
	}

	bool operator==(const edge &other) const {
		return key == other.key;
	}
};

class prim {
public:
	explicit prim(graph g);

	std::vector<size_t> mst(size_t r) const;

private:
	graph g_;
	
	std::vector<vertex> nodes_;
	std::vector<bool> inq_;
};

#endif // PRIM_H
