#pragma once
#include <vector>
using namespace std;

class DSU {
    vector<int> p, r;
public:
    DSU(int n);
    int find(int x);
    bool unite(int a, int b);
};