#include "ufset.h"

ufset::ufset(size_t n)
	:count_{n}
	,ids_(n, 0)
	,sz_(n, 1)
{
	for (size_t i = 0; i != ids_.size(); ++i)
		ids_[i] = i;
}

bool ufset::connected(int p, int q) const {
	return find(p) == find(q);
}

int ufset::find(int q) const {
	while (q != ids_[q]) q = ids_[q];
	return q;
}

void ufset::doUnion(int p, int q) {
	int i = find(p);
	int j = find(q);
	if (i == j) return;

	if (sz_[i] > sz_[j]) {
		ids_[i] = j;
		sz_[j] += sz_[i];
	} else {
		ids_[j] = i;
		sz_[i] += sz_[j];
	}

	--count_;
}

size_t ufset::count() const {
	return count_;
}
