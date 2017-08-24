#ifndef GRAPH_H
#define GRAPH_H

#include "container/vector.h"
#include "utility/range.h"
#include <stddef.h>

#include <iostream>
#include <fstream>

template <typename T>
using Vector = toys::container::vector<T>;

class Graph {
public:
	explicit Graph(size_t v);
	//explicit Graph(std::ifstream &istream);
	
	size_t V() const;
	size_t E() const;

	void addEdge(int v, int w);
	Vector<int> Adj(int v);
private:
	// count of vertexs
	size_t v_;
	// count of edges
	size_t e_;
	// adjacency table
	Vector<Vector<int>> adj_;
};

#endif // GRAPH_H
