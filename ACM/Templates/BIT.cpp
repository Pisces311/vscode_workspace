#include <bits/stdc++.h>
using namespace std;

template <class T = int>
class BIT {
   public:
    int n;
    vector<T> bit;

    BIT(int n) : n(n) { bit.assign(n, 0); }

    BIT(vector<int>& a) : BIT(a.size()) {
        for (int i = 0; i < a.size(); i++) add(i, a[i]);
    }

    T sum(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
        return ret;
    }

    T sum(int l, int r) { return sum(r) - sum(l - 1); }

    void add(int i, T delta) {
        for (; i < n; i = i | (i + 1)) bit[i] += delta;
    }
};