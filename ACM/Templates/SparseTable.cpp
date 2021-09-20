#include <bits/stdc++.h>
using namespace std;

class SparseTable {
    vector<vector<int>> Min, Max;

   public:
    SparseTable(vector<int>& nums) {
        int n = nums.size();
        int k = log2(n) + 5;
        Min.resize(n, vector<int>(k));
        Max.resize(n, vector<int>(k));
        for (int i = 0; i < n; i++) Min[i][0] = Max[i][0] = nums[i];
        for (int i = 1; (1 << i) <= n; ++i) {
            for (int j = 0; j + (1 << i) - 1 < n; j++) {
                Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
                Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int qmax(int l, int r) {
        int k = log2(r - l + 1);
        return max(Max[l][k], Max[r - (1 << k) + 1][k]);
    }

    int qmin(int l, int r) {
        int k = log2(r - l + 1);
        return min(Min[l][k], Min[r - (1 << k) + 1][k]);
    }
};