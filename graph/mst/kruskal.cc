#include "kruskal.h"
// for std::sort
#include <algorithm>

#include "utility/MinPQ.h"
#include "utility/ufset.h"

bool edge::operator<(const edge &other) const {
	return weight < other.weight;
}

kruskal::kruskal() {}

kruskal::kruskal(std::istream &in) {
	unsigned v;
	in >> v;
	v_ = v;

	int v = 0;
	int w = 0;
	double weight = 0.0;
	while (in >> v >> w >> weight) {
		edges_.emplace_back({v, w, weight});
	}
}

// CLRS(3th) P366
std::vector<edge> kruskal::mst() const {
	std::vector<edge> result;

	// for each vertex v, MAKE-SET(v)
	ufset uf(v_);

	// sort the edges of G.E into nondecreasing order by weight w
	std::sort(edges_.begin(), edges_.end());

	for (const edge &e : edges_) {
		if (uf.find(e.v) != uf.find(e.w)) {
			result.push_back(e);
			uf.doUnion(e.v, e.w);
		}
	}
	
	return result;
}
