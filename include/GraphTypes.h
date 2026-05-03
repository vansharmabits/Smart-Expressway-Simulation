#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, dist, time, toll;
};

struct Road {
    int u, v, w;
    bool operator<(const Road& o) const {
        return w < o.w;
    }
};