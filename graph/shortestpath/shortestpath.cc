#include "shortestpath.h"

#include "../../utility/MinPQ.h"

ShortestPath::ShortestPath(const weighted_dag &g)
	:g_{g}
	,vertexes_(g_.V())
{ }

bool ShortestPath::bellman_ford(size_t s) {
	init(s);

	for (size_t i = 1; i != g_.V() - 1; ++i) {
		for (size_t u = 0; u != g_.V(); ++u) {
			for (size_t v : g_.adj(u)) {
				relax(u, v);
			}
		}
	}

	//for (size_t u = 0; u != g_.V(); ++u) {
	//	for (size_t v : g_.adj(u)) {
	//		if (vertexes_[v].d > vertexes_[u].d + g_.weight(u, v)) {
	//			return false;
	//		}
	//	}
	//}

	return true;
}

static bool vertex_equals(const vertex &lhs, const vertex &rhs) {
	return lhs.rank == rhs.rank;
}

std::vector<vertex> ShortestPath::dijkstra(size_t s) {
	init(s);

	MinPQ<vertex> Q;
	for (const auto &v : vertexes_)
		Q.insert(v);

	while (!Q.empty()) {
		vertex unode = Q.delMin();
		size_t u = unode.rank;
		
		for (size_t v : g_.adj(u)) {
			relax(u, v);

			if (vertexes_[v].d > vertexes_[u].d + g_.weight(u, v)) {
				vertex findv;
				findv.rank = v;
				size_t idx = Q.findKey(findv, vertex_equals);
				if (idx != static_cast<size_t>(-1)) {
					Q.decreaseKey(idx, vertexes_[v]);
				}
			}
		}
	}

	return vertexes_;
}

void ShortestPath::init(size_t s) {
	for (size_t i = 0; i != vertexes_.size(); ++i) {
		vertexes_[i].rank = i;
		vertexes_[i].parent = i;
	}

	vertexes_[s].d = 0;
}

void ShortestPath::relax(size_t u, size_t v) {
	if (vertexes_[v].d > vertexes_[u].d + g_.weight(u, v)) {
		vertexes_[v].d = vertexes_[u].d + g_.weight(u, v);
		vertexes_[v].parent = u;
	}
}
