#include "../include/Fenwick.h"

Fenwick::Fenwick(int n) {
    this->n = n;
    bit.assign(n+1, 0);
}

void Fenwick::update(int i, int delta) {
    for(; i <= n; i += i & -i)
        bit[i] += delta;
}

int Fenwick::query(int i) {
    int sum = 0;
    for(; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

int Fenwick::range(int l, int r) {
    return query(r) - query(l-1);
}