#include "scc.h"

SCC::SCC(dag g)
	:sgraph_{g.reverse()} 
	,marked_(g.V(), false)
	,id_(g.V(), 0)
	,count_(0)
{
	g.dfs();
	for (size_t s : g.reverseOrder()) {
		if (!marked_[s]) {
			dfs(s);
			++count_;
		}
	}
}

void SCC::dfs(size_t v) {
	marked_[v] = true;
	id_[v] = count_;

	for (size_t w : sgraph_.adj(v)) {
		if (!marked_[w]) {
			dfs(w);
		}
	}
}

bool SCC::stronglyConnected(size_t v, size_t w) {
	return id_[v] == id_[w];
}

size_t SCC::id(size_t v) const {
	return id_[v];
}

size_t SCC::count() const {
	return count_ + 1;
}
