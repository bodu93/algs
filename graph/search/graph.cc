#include "graph.h"
#include <queue>

int graph::time = 0;

graph::graph(std::istream &in) {
	unsigned vcount, ecount;
	in >> vcount;

	adjTable_.resize(vcount);

	int v, w;
	while (in >> v >> w) {
		addEdge(v, w);
	}
}

size_t graph::V() const {
	return adjTable_.size();
}

size_t graph::E() const {
	return e_;
}

void graph::addEdge(int v, int w) {
	auto &vadj = adjTable_[v];
	vadj.adj.push_back(w);

	auto &wadj = adjTable_[w];
	wadj.adj.push_back(v);

	++e_;
}

graph graph::reverse() {
	graph r;
	r.resize(V());

	size_t rank = 0;
	for (const auto &v : adjTable_) {
		for (int va : v.adj) {
			r.addEdge(va, rank);
		}
		++rank;
	}

	return r;
}

Vector<int> graph::adj(int v) const {
	return adjTable_[v].adj;
}

const vertex& graph::node(int v) const {
	return adjTable_[v];
}

void graph::bfs(int s) {
	vertex &snode = adjTable_[s];
	snode.color = Color::eGray;
	snode.d = 0;
	
	std::queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vertex &unode = adjTable_[u];

		for (int v : unode.adj) {
			vertex &vnode = adjTable_[v];
			if (vnode.color == Color::eWhite) {
				vnode.color = Color::eGray;
				vnode.d = unode.d + 1;
				vnode.p = u;

				q.push(v);
			}
		}

		unode.color = Color::eBlack;
	}
}

Vector<int> graph::reverseOrder() {
	Vector<int> result;

	while (!reverseOrder_.empty()) {
		result.push_back(reverseOrder_.top());
		reverseOrder_.pop();
	}

	return result;
}

void graph::dfs(int s) {
	time = 0;

	for (const auto &v : adjTable_) {
		if (v.color == Color::eWhite) {
			dfs_visit(s);
		}
	}
	
	time = 0;
}

void graph::dfs_visit(int u) {
	vertex &unode = adjTable_[u];
	unode.d = ++time;
	unode.color = Color::eGray;
	
	preOrder_.push_back(u);
	for (int v : unode.adj) {
		vertex &vnode = adjTable_[v];
		if (vnode.color == Color::eWhite) {
			vnode.p = u;
			dfs_visit(v);
		} else if(vnode.color == Color::eGray) {
			// back-edge, the graph has circle...
		} else { // vnode.color == Color::eBlack
			// if unode.d < vnode.d, front-edge
			// else if unode.d > vnode.d, cross-edge
		}
	}
	postOrder_.push_back(u);
	reverseOrder_.push(u);

	unode.color = Color::eBlack;
	unode.f = ++time;
}


std::ostream &operator<<(std::ostream &os, const graph &g) {
	size_t rank = 0;
	
	for (const auto &v : g.adjTable_) {
		//for (auto i : v.adj)
		//	os << i << " ";
		//os << std::endl;
		os << rank++ << " "
			<< static_cast<int>(v.color) << " "
			<< v.d << " "
			<< v.p << std::endl;
	}

	return os;
}
