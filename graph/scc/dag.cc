#include "dag.h"

dag::dag(std::istream &in) {
	if (!in.fail()) {
		unsigned V;
		in >> V;
		adjTable_.resize(V);
		marked_.resize(V);
		for (size_t i = 0; i != marked_.size(); ++i)
			marked_[i] = false;

		unsigned v, w;
		while (in >> v >> w) {
			addedge(static_cast<size_t>(v), static_cast<size_t>(w));
		}
	}
}

void dag::addedge(size_t v, size_t w) {
	adjTable_[v].push_back(w);
}

dag dag::reverse() {
	dag r;
	r.adjTable_.resize(V());
	r.marked_.resize(V());
	for (size_t i = 0; i != marked_.size(); ++i)
		marked_[i] = false;

	
	for (size_t v = 0; v != adjTable_.size(); ++v) {
		for (size_t w : adjTable_[v])
			r.addedge(w, v);
	}

	return r;
}

std::vector<size_t> dag::reverseOrder() {
	std::vector<size_t> result;

	while (!reversePost_.empty()) {
		result.push_back(reversePost_.top());
		reversePost_.pop();
	}

	return result;
}

void dag::dfs() {
	for (size_t i = 0; i != V(); ++i) {
		if (!marked_[i])
			dfs_visit(i);
	}
}

void dag::dfs_visit(size_t u) {
	marked_[u] = true;
	for (size_t v : adj(u)) {
		if (!marked_[v])
			dfs_visit(v);
	}

	reversePost_.push(u);
}
