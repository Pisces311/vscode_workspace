#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto check = [&](int mid) {
            int cnt = 0;
            for (int& i : quantities) cnt += (i + mid - 1) / mid;
            return cnt <= n;
        };

        int l = 1, r = *max_element(quantities.begin(), quantities.end());
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return r + 1;
    }
};

int main() {
    Solution sol;
    vector<int> quantities = {11, 6};
    cout << sol.minimizedMaximum(6, quantities) << endl;
    return 0;
}