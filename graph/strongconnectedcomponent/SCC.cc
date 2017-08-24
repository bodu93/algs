#include "SCC.h"

SCC::SCC(graph g)
	:sgraph_{g} 
	,marked_(g.V(), false)
	,id_(g.V(), 0)
	,count_(0)
{
	graph r = g.reverse();
	for (int s : r.reverseOrder()) {
		if (!marked_[s]) {
			dfs(s);
			++count_;
		}
	}
}

void SCC::dfs(int v) {
	marked_[v] = true;
	id_[v] = count_;

	for (int w : sgraph_.adj(v)) {
		if (!marked_[w])
			dfs(w);
	}
}

bool SCC::stronglyConnected(int v, int w) {
	return id_[v] == id_[w];
}

size_t SCC::id(int v) const {
	return id_[v];
}

size_t SCC::count() const {
	return count_;
}
