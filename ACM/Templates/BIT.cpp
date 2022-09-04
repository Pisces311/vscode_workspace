#include <bits/stdc++.h>
using namespace std;

template <class T = int>
class BIT {
    int n;
    vector<T> bit;

    T sum(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
        return ret;
    }

   public:
    BIT(int n) : n(n) { bit.assign(n, 0); }

    BIT(vector<int>& a) : BIT(a.size()) {
        for (int i = 0; i < a.size(); i++) add(i, a[i]);
    }

    T sum(int l, int r) { return sum(r) - sum(l - 1); }

    void add(int i, T val) {
        for (; i < n; i = i | (i + 1)) bit[i] += val;
    }
};