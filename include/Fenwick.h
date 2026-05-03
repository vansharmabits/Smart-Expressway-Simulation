#pragma once
#include <vector>
using namespace std;

class Fenwick {
    int n;
    vector<int> bit;
public:
    Fenwick(int n);
    void update(int i, int delta);
    int query(int i);
    int range(int l, int r);
};