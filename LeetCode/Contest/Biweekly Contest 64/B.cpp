#include <bits/stdc++.h>
using namespace std;

class Solution {
    int bisearch(vector<vector<int>>& events, int i) {
        int n = events.size();
        int l = 0, r = n - 1;
        int ans = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (events[mid][0] > events[i][1]) {
                r = mid - 1;
                ans = mid;
            } else
                l = mid + 1;
        }
        return ans;
    }

   public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(),
             [&](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        vector<int> maxv(n);
        maxv[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            maxv[i] = max(events[i][2], maxv[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cur = events[i][2];
            int p = bisearch(events, i);
            if (p != n) cur += maxv[p];
            ans = max(ans, cur);
        }
        return ans;
    }
};