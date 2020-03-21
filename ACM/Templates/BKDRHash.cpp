#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 1e5 + 5;

ull BKDRHash(const char *str, int l, int r) {
    ull seed = 131;  // 31 131 1313 13131 131313 etc..
    ull hash = 0;
    for (int i = l; i <= r; ++i) hash = hash * seed + str[i];
    return (hash & 0xFFFFFFFFFFFFFFFF);
}