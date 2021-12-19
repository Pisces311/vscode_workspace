#include <bits/stdc++.h>
using namespace std;

struct LIS {
    vector<int> a, stk;

   public:
    LIS(vector<int>& arr) : a(arr) { stk.clear(); }

    int solve() {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (stk.empty() || a[i] >= stk.back())
                stk.push_back(a[i]);
            else {
                int p = upper_bound(stk.begin(), stk.end(), a[i]) - stk.begin();
                stk[p] = a[i];
            }
        }
        return stk.size();
    }
};

class Solution {
   public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0;
        for (int i = 0; i < k; i++) {
            vector<int> tmp;
            for (int j = i; j < arr.size(); j += k) tmp.push_back(arr[j]);
            LIS lis(tmp);
            ans += tmp.size() - lis.solve();
        }
        return ans;
    }
};