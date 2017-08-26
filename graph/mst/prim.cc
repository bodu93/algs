#include "prim.h"
#include "utility/MinPQ.h"

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



prim::prim(graph g)
	:g_(g)
	 ,nodes_(g.V())
	 ,inq_(g.V(), false)
{
	for (size_t i = 0; i != g_.V(); ++i) {
		nodes_[i].parent = i;
		nodes_[i].to = i;
	}
}

static bool vertex_equals(const vertex &lhs, const vertex &rhs) {
	return lhs.to == rhs.to;
}

// CLRS(3th) P369
std::vector<size_t> prim::mst(size_t r) const {
	nodes_[r].weight = 0;
	
	MinPQ<vertex> Q;
	for (const auto &v : nodes_)
		Q.insert(v);

	while (!Q.empty()) {
		const vertex &u = Q.delMin();
		inq_[u.to()] = true;
		for (size_t v : g_.adj(u.to())) {
			if (inq_[v] && g_.weight(u.to(), v) < nodes_[v].key) {
				nodes_[v].parent = u.to();
				nodes_[v].key = g_.weight(u.to(), v);
				// update v.key = w(u, v) in Q
				vertex findv;
				findv.to = v;
				size_t idx = Q.findKey(findv, vertex_equals);
				if (idx != static_cast<size_t>(-1)) {
					Q.decreaseKey(idx, g_.weight(u.to(), v);
				}
			}
		}
	}
}
