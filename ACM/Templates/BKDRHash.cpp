#include <bits/stdc++.h>
using namespace std;

// Seed options: 31, 131, 1313, 13131, 131313...
class BKDRHash {
    using ull = unsigned long long;
    ull seed;

   public:
    BKDRHash(ull seed) : seed(seed) {}
    ull get(string str, int l, int r) {
        ull hash = 0;
        for (int i = l; i <= r; ++i) hash = hash * seed + str[i];
        return (hash & 0xFFFFFFFFFFFFFFFF);
    }
};