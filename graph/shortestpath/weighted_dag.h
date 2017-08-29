#ifndef WEIGHTED_DAG_H
#define WEIGHTED_DAG_H

#include <vector>
// for size_t
#include <stddef.h>
// for std::istream
#include <istream>

// adjacency matrix
class weighted_dag {
public:
	explicit weighted_dag(size_t n);
	explicit weighted_dag(std::istream &in);

	std::vector<size_t> adj(size_t v) const;

	size_t V() const;

	// -1 for non-edge between v and w
	double weight(size_t v, size_t w) const;

	void addedge(size_t v, size_t w, int weight);

private:
	std::vector<double> adjmatrix_;
	size_t v_;

	double &edge(size_t v, size_t w);
	double edge(size_t v, size_t w) const;
};

#endif // WEIGHTED_DAG_H
