#include "graph.h"

Graph::Graph(size_t v) : v_{0}, e_{0}, adj_{v_} { }

size_t Graph::V() const {
	return v_;
}

size_t Graph::E() const {
	return e_;
}

void Graph::addEdge(int v, int w) const {
	auto &vv = adj_[v];
	vv.push_back(w);

	auto &wv = adj_[w];
	wv.push_back(v);
	
	++e_;
}

Vector<int> Graph::Adj(int v) {
	return adj_[v];
}
