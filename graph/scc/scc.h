#ifndef SCC_H
#define SCC_H

#include "../search/graph.h"

class SCC {
public:
	explicit SCC(graph r);
	bool stronglyConnected(int v, int w);
	size_t count() const;
	size_t id(int v) const;


private:
	void dfs(int v);

	graph			sgraph_;

	Vector<bool>	marked_;
	Vector<size_t>	id_;
	size_t			count_;
};

#endif // SCC_H
