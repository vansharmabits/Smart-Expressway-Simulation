#pragma once
#include <vector>
#include <string>
using namespace std;

class BloomFilter {
    int m, k;
    vector<bool> bits;
    vector<int> seeds;
    long long hashFunc(const string&, int);
public:
    BloomFilter(int size=200000, int hashCnt=4);
    void add(const string&);
    bool possiblyExists(const string&);
};