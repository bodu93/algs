#include "graph.h"
// for std::numeric_limits<double>::max
#include <limits>

graph::graph(size_t n)
	:adjmatrix_(n * n, std::numeric_limits<double>::max())
	 ,v_(n)
{ }

graph::graph(std::istream &in) {
	unsigned V = 0;
	in >> V;
	v_ = V;
	adjmatrix_.resize(V * V);
	for (auto &v : adjmatrix_)
		v = std::numeric_limits<double>::max();

	unsigned v = 0;
	unsigned w = 0;
	double weight = 0.0;
	while (in >> v >> w >> weight) {
		addedge(v, w, weight);
	}
}

std::vector<size_t> graph::adj(size_t v) const {
	std::vector<size_t> result;

	for (size_t i = 0; i != V(); ++i) {
		if (edge(v, i) != std::numeric_limits<double>::max()) {
			result.push_back(i);
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
	edge(w, v) = weight;
}

double& graph::edge(size_t v, size_t w) {
	return adjmatrix_[v * V() + w];
}

double graph::edge(size_t v, size_t w) const {
	return adjmatrix_[v * V() + w];
}
