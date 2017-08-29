#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <istream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <limits>

struct edge {
	int v{-1};
	int w{-1};
	double weight{std::numeric_limits<double>::min()};

	explicit edge(int v, int w, double weight)
		:v(v)
		 ,w(w)
		 ,weight(weight)
	{ }

	bool operator<(const edge &other) const;
	bool operator==(const edge &other) const;

	friend void swap(edge &l, edge &r) noexcept {
		std::swap(l.v, r.v);
		std::swap(l.w, r.w);
		std::swap(l.weight, r.weight);
	}

	friend std::ostream &operator<<(std::ostream &os, const edge &e) {
		os << e.v << " to " << e.w << " , weighted: " << e.weight << std::endl;
		return os;
	}
};


class kruskal {
public:
	kruskal();
	explicit kruskal(std::istream &in);

	std::vector<edge> mst();	

private:
	std::vector<edge>	edges_;
	size_t				v_{0};
};

#endif // KRUSKAL_H
