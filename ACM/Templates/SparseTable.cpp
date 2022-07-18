#include <bits/stdc++.h>
using namespace std;

template <class T = int>
class SparseTable {
    vector<vector<T>> _min, _max;

   public:
    SparseTable(vector<T>& nums) {
        int n = nums.size();
        int k = log2(n) + 5;
        _min.assign(n, vector<T>(k));
        _max.assign(n, vector<T>(k));
        for (int i = 0; i < n; i++) _min[i][0] = _max[i][0] = nums[i];
        for (int i = 1; (1 << i) <= n; i++) {
            for (int j = 0; j + (1 << i) - 1 < n; j++) {
                _max[j][i] = max(_max[j][i - 1], _max[j + (1 << (i - 1))][i - 1]);
                _min[j][i] = min(_min[j][i - 1], _min[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    T qmax(int l, int r) {
        int k = log2(r - l + 1);
        return max(_max[l][k], _max[r - (1 << k) + 1][k]);
    }

    T qmin(int l, int r) {
        int k = log2(r - l + 1);
        return min(_min[l][k], _min[r - (1 << k) + 1][k]);
    }
};