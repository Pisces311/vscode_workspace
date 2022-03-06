#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
   public:
    bool check(vector<int>& time, ll mid, ll total) {
        ll cur = 0;
        for (int i : time) {
            cur += mid / i;
        }
        return cur >= total;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 1, r = 1e14;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check(time, mid, totalTrips)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r + 1;
    }
};