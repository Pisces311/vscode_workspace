#include <bits/stdc++.h>
using namespace std;

// longest increasing subsequence
struct LIS {
    vector<int> a, stk;

   public:
    LIS(vector<int>& arr) : a(arr) { stk.clear(); }

    int solve() {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (stk.empty() || a[i] > stk.back())
                stk.push_back(a[i]);
            else {
                int p = lower_bound(stk.begin(), stk.end(), a[i]) - stk.begin();
                stk[p] = a[i];
            }
        }
        return stk.size();
    }
};

// longest non-decreasing subsequence
struct LNDS {
    vector<int> a, stk;

   public:
    LNDS(vector<int>& arr) : a(arr) { stk.clear(); }

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