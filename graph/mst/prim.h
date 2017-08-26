#ifndef PRIM_H
#define PRIM_H

#include <istream>
#include <vector>
#include <stddef.h>

class graph {
public:
	explicit graph(size_t n);
	explicit graph(std::istream &in);

	std::vector<size_t> adj(size_t v) const;

	size_t V() const;

	// -1 for non-edge between v and w
	double weight(size_t v, size_t w) const;

	void addedge(size_t v, size_t w, int weight);

private:
	std::vector<double> adjmatrix_;
	size_t v_;

	double &edge(size_t v, size_t w);
};

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
