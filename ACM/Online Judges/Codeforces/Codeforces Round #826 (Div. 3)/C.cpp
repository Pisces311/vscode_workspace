#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int ans = n;
    for (int len = 1; len <= n; len++) {
        int sum = accumulate(a.begin(), a.begin() + len, 0);
        int cur_sum = 0, cur = 0, cur_ans = len;
        for (int i = len; i < n; i++) {
            if (cur_sum < sum) {
                cur_sum += a[i];
                cur++;
            }
            if (cur_sum == sum) {
                cur_sum = 0;
                cur_ans = max(cur_ans, cur);
                cur = 0;
            } else if (cur_sum > sum || cur_sum < sum && i == n - 1) {
                cur_ans = n;
                break;
            }
        }
        ans = min(ans, cur_ans);
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }

    return 0;
}