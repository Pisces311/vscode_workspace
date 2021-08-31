#include <bits/stdc++.h>
using namespace std;

struct job {
    int s, e, p;
    bool operator<(const job& a) const { return s < a.s; }
    bool operator<(const int a) const { return s < a; }
};

class Solution {
   public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        vector<job> a;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            a.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(a.begin(), a.end());
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(a[i].p, dp[i + 1]);
            int p = lower_bound(a.begin(), a.end(), a[i].e) - a.begin();
            if (p != n) dp[i] = max(dp[i], a[i].p + dp[p]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution a;
    vector<int> start = {1, 2, 3, 4, 6}, end = {3, 5, 10, 6, 9},
                profit = {20, 20, 100, 70, 60};
    cout << a.jobScheduling(start, end, profit) << endl;
    return 0;
}