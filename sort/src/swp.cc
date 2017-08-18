#include "../include/swp.h"

void swap_(int *p, int *q) {
	int t = *p;
	*p = *q;
	*q = t;
}
