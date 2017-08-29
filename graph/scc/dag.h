#ifndef DAG_H
#define DAG_H

#include <istream>
#include <vector>
#include <stack>

class dag {
public:
	dag() { }
	explicit dag(std::istream &in);

	size_t V() const { return adjTable_.size(); }
	std::vector<size_t> adj(size_t v) const { return adjTable_[v]; }
	void addedge(size_t v, size_t w);
	dag reverse();
	void dfs();
	std::vector<size_t> reverseOrder();
private:
	std::vector<std::vector<size_t>> adjTable_;
	std::stack<size_t> reversePost_;
	std::vector<bool> marked_;

	void dfs_visit(size_t u);
};


#endif // DAG_H
