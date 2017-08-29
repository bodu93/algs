#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stack>
#include <istream>

enum class Color {
	eWhite,
	eGray,
	eBlack
};

struct vertex {
	Color		color;	// visit state

	int			d;		// distance from source vertex in bfs-tree
						// or first visit time in dfs-tree
						
	int			f;		// last visit time in dfs-tree
	
	int			p;		// parent in bfs-tree or dfs-tree

	std::vector<int> adj;	// adj...

	vertex()
		: color(Color::eWhite)
		,d(-1) // -1 for unknown
		,f(-1) // -1 for unknown
		,p(-1) // -1 for empty
	{ }
};

// adjacency list
class graph {
public:
	friend std::ostream &operator<<(std::ostream &os, const graph &g);

	graph() { }
	explicit graph(std::istream &in);

	size_t V() const;
	size_t E() const;
	void addEdge(int v, int w);

	std::vector<int> adj(int v) const;
	const vertex &node(int v) const;
	
	// breadth-first-search
	void bfs(int s);

	// depth-first-search
	void dfs();

	// topological order
	std::vector<int> reverseOrder();

	// reverse
	graph reverse();
private:
	void dfs_visit(int s);

	size_t e_{ 0 };

	std::vector<vertex> adjTable_;


	std::vector<int> preOrder_;
	std::vector<int> postOrder_;
	std::stack<int> reverseOrder_;		// topological order

	static int time;					// for dfs visit time
};

std::ostream &operator<<(std::ostream &, const graph &);

#endif // GRAPH_H
