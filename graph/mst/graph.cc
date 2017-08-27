#include "graph.h"

graph::graph(size_t n)
	:adjmatrix_(n * n, -1.0)
	 ,v_(n)
{ }

graph::graph(std::istream &in) {
	unsigned v = 0;
	in >> v;
	v_ = v;

	unsigned v = 0;
	unsigned w = 0;
	double weight = 0.0;
	while (in >> v >> w >> weight) {
		addedge(v, w, weight);
	}
}

std::vector<size_t> graph::adj(size_t v) const {
	std::vector<size_t> result;

	size_t brank = v * v_;
	size_t erank = (v + 1) * v_;
	for (size_t i = brank; i != erank; ++i) {
		if (adjmatrix_[i] != -1) {
			result.push_back(i - brank);
		}
	}

	return result;
}

size_t graph::V() const {
	return v_;
}

double graph::weight(size_t v, size_t w) const {
	return edge(v, w);
}

void graph::addedge(size_t v, size_t w, int weight) {
	edge(v, w) = weight;
}

double& graph::edge(size_t v, size_t w) {
	return adjmatrix_[v * w];
}
