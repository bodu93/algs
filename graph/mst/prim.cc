#include "prim.h"
#include "../../utility/MinPQ.h"

prim::prim(graph g)
	:g_(g)
	 ,nodes_(g.V())
	 ,inq_(g.V(), true)
{
	for (size_t i = 0; i != g_.V(); ++i) {
		nodes_[i].parent = i;
		nodes_[i].rank = i;
	}
}

static bool vertex_equals(const vertex &lhs, const vertex &rhs) {
	return lhs.rank == rhs.rank;
}

// CLRS(3th) P369
std::vector<vertex> prim::mst(size_t r) {
	nodes_[r].key = 0;
	
	MinPQ<vertex> Q;
	for (const auto &v : nodes_) {
		Q.insert(v);
	}

	while (!Q.empty()) {
		const vertex &unode = Q.delMin();
		size_t u = unode.rank;
		inq_[u] = false;
		for (size_t v : g_.adj(u)) {
			if (inq_[v] && (g_.weight(u, v) < nodes_[v].key)) {
				nodes_[v].parent = u;
				nodes_[v].key = g_.weight(u, v);
				// update v.key = w(u, v) in Q
				vertex findv;
				findv.rank = v;
				size_t idx = Q.findKey(findv, vertex_equals);
				if (idx != static_cast<size_t>(-1)) {
					Q.decreaseKey(idx, nodes_[v]);
				}
			}
		}
	}

	return nodes_;
}
