#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> &a, int l, int r, int s, int &ans) {
    int mid = (l + r) / 2, len = (r - l + 1) / 2;
    if (l == r) return a[l] == s;
    if (a[l] - s < len) {
        return dfs(a, l, mid, s, ans) && dfs(a, mid + 1, r, s + len, ans);
    } else {
        ans++;
        return dfs(a, l, mid, s + len, ans) && dfs(a, mid + 1, r, s, ans);
    }
}

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int ans = 0;
    if (dfs(a, 0, n - 1, 1, ans)) return ans;
    return -1;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }

    return 0;
}