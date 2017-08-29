#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "../mst/graph.h"
#include <limits>
#include <vector>

struct vertex {
	size_t rank{-1};
	size_t parent{-1};
	double d{std::numeric_limits<double>::max()};

	bool operator<(const vertex &other) const {
		return d < other.d;
	}

	bool operator<=(const vertex &other) const {
		return d <= other.d;
	}	

	bool operator==(const vertex &other) const {
		return d == other.d;
	}
};

class ShortestPath {
public:
	explicit ShortestPath(const graph &g);

	bool bellman_ford(size_t s);
	void dijkstra(size_t s);
private:
	void init(size_t s);
	void relax(size_t u, size_t v);

	graph g_;
	std::vector<vertex> vertexes_;
};

#endif // SHORTESTPATH_H
