#include "../include/BloomFilter.h"

BloomFilter::BloomFilter(int size, int hashCnt) {
    m = size;
    k = hashCnt;
    bits.resize(m, false);

    for(int i = 0; i < k; i++)
        seeds.push_back(i * 31 + 7);
}

long long BloomFilter::hashFunc(const string& s, int seed) {
    long long h = 0;
    for(char c : s)
        h = (h * seed + c) % m;
    return h;
}

void BloomFilter::add(const string& s) {
    for(int i = 0; i < k; i++)
        bits[hashFunc(s, seeds[i])] = true;
}

bool BloomFilter::possiblyExists(const string& s) {
    for(int i = 0; i < k; i++) {
        if(!bits[hashFunc(s, seeds[i])])
            return false;
    }
    return true;
}