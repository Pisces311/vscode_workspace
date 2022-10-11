#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SparseTable {
    using func_type = function<T(const T &, const T &)>;

    vector<vector<T>> ST;
    func_type op;

    static T default_func(const T &t1, const T &t2) { return max(t1, t2); }

   public:
    SparseTable(const vector<T> &v, func_type _func = default_func) {
        op = _func;
        int n = v.size(), k = log2(n) + 5;
        ST.assign(n, vector<T>(k));
        for (int i = 0; i < n; ++i) ST[i][0] = v[i];
        for (int i = 1; (1 << i) <= n; i++) {
            for (int j = 0; j + (1 << i) - 1 < n; j++) {
                ST[j][i] = op(ST[j][i - 1], ST[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    T query(int l, int r) {
        int k = log2(r - l + 1);
        return op(ST[l][k], ST[r - (1 << k) + 1][k]);
    }
};