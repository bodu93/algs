#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
// for size_t
#include <stddef.h>
// for std::istream
#include <istream>

// adjacency matrix
class graph {
public:
	explicit graph(size_t n);
	explicit graph(std::istream &in);

	std::vector<size_t> adj(size_t v) const;

	size_t V() const;

	// -1 for non-edge between v and w
	double weight(size_t v, size_t w);

	void addedge(size_t v, size_t w, int weight);

private:
	std::vector<double> adjmatrix_;
	size_t v_;

	double &edge(size_t v, size_t w);
};

#endif // GRAPH_H
