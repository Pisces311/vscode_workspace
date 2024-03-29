#include <bits/stdc++.h>
using namespace std;

template <class T = int>
class SparseTable {
    vector<vector<T>> Min, Max;

   public:
    SparseTable(vector<T>& nums) {
        int n = nums.size();
        int k = log2(n) + 5;
        Min.resize(n, vector<T>(k));
        Max.resize(n, vector<T>(k));
        for (int i = 0; i < n; i++) Min[i][0] = Max[i][0] = nums[i];
        for (int i = 1; (1 << i) <= n; i++) {
            for (int j = 0; j + (1 << i) - 1 < n; j++) {
                Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
                Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    T qmax(int l, int r) {
        int k = log2(r - l + 1);
        return max(Max[l][k], Max[r - (1 << k) + 1][k]);
    }

    T qmin(int l, int r) {
        int k = log2(r - l + 1);
        return min(Min[l][k], Min[r - (1 << k) + 1][k]);
    }
};

class Solution {
   public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> beauty(n);
        SparseTable st(nums);
        for (int i = 1; i < n - 1; i++) {
            if (st.qmax(0, i - 1) < nums[i] && nums[i] < st.qmin(i + 1, n - 1))
                beauty[i] = 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                beauty[i] = 1;
        }
        return accumulate(beauty.begin(), beauty.end(), 0);
    }
};