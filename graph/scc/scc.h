#ifndef SCC_H
#define SCC_H

#include "dag.h"

class SCC {
public:
	explicit SCC(dag r);
	bool stronglyConnected(size_t v, size_t w);
	size_t count() const;
	size_t id(size_t v) const;


private:
	void dfs(size_t v);

	dag						sgraph_;
	std::vector<bool>		marked_;
	std::vector<size_t>		id_;
	size_t					count_;
};

#endif // SCC_H
