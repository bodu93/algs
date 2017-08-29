#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "weighted_dag.h"
#include <limits>
#include <vector>
#include <ostream>

struct vertex {
	size_t rank{static_cast<size_t>(-1)};
	size_t parent{static_cast<size_t>(-1)};
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

	friend std::ostream &operator<<(std::ostream &os, const vertex &v) {
		os << "rank: " << v.rank << " , parent: " << v.parent << " , shortest_distance: " << v.d << std::endl;
		return os;
	}
};

class ShortestPath {
public:
	friend std::ostream &operator<<(std::ostream &os, const ShortestPath &sp) {
		for (auto v : sp.vertexes_)
			os << v << std::endl;
		return os;
	}

	explicit ShortestPath(const weighted_dag &g);

	bool bellman_ford(size_t s);
	std::vector<vertex> dijkstra(size_t s);
private:
	void init(size_t s);
	void relax(size_t u, size_t v);

	weighted_dag g_;
	std::vector<vertex> vertexes_;
};

#endif // SHORTESTPATH_H
