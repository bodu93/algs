#include "prim.h"
#include "utility/MinPQ.h"

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
