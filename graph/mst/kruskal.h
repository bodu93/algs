#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <istream>
#include <vector>

struct edge {
	int v{-1};
	int w{-1};
	double weight{-1.0};

	explicit edge(int v, int w, double weight)
		:v(v)
		 ,w(w)
		 ,weight(weight)
	{ }

	bool operator<(const edge &other) const;
};


class kruskal {
public:
	kruskal();
	explicit kruskal(std::istream &in);

	std::vector<edge> mst() const;	

private:
	std::vector<int>	edges_;
	size_t				v_{0};
};

#endif // KRUSKAL_H
