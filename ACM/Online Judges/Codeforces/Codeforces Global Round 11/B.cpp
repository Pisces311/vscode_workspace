#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, k;
char s[maxn];
vector<int> ans;
int ret;

bool every(char ch) {
    for (int i = 1; i <= n; ++i)
        if (s[i] != ch) return false;
    return true;
}

bool check() {
    if (every('L'))
        ret = max(0, 2 * min(n, k) - 1);
    else if (every('W'))
        ret = 2 * n - 1;
    else
        return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ans.clear();
        cin >> n >> k;
        cin >> (s + 1);
        int tot = 0, all = 0;
        for (int i = 1; i <= n; ++i)
            if (s[i] == 'W')
                tot += 1 + (s[i - 1] == 'W');
            else
                ++all;
        int l, r;
        for (l = 1; l < n && s[l] == 'L'; ++l)
            ;
        for (r = n; r > 1 && s[r] == 'L'; --r)
            ;
        if (check())
            cout << ret << '\n';
        else {
            for (int i = l; i <= r; ++i) {
                if (s[i] == 'L') {
                    int cnt = 0;
                    while (s[i] == 'L') {
                        ++cnt;
                        ++i;
                    }
                    ans.push_back(cnt);
                }
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); ++i) {
                if (k >= ans[i]) {
                    k -= ans[i];
                    tot += 2 * ans[i] + 1;
                    all -= ans[i];
                } else
                    break;
            }
            tot += 2 * min(k, all);
            cout << tot << '\n';
        }
    }

    return 0;
}