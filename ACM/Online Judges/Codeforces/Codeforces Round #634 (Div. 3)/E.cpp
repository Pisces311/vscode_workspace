#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int t, n, l, r;
int a[maxn], num[205];
vector<int> pos[205];

inline void init() {
    for (int i = 1; i <= 200; ++i) pos[i].clear();
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        init();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        int ans = 0;
        for (int i = 1; i <= 200; ++i) {
            int cnt = pos[i].size() / 2;
            memset(num, 0, sizeof(num));
            if (pos[i].size() > 1) {
                if (pos[i].size() & 1) {
                    l = pos[i][pos[i].size() / 2 - 1],
                    r = pos[i][pos[i].size() / 2 + 1];
                } else {
                    l = pos[i][pos[i].size() / 2 - 1],
                    r = pos[i][pos[i].size() / 2];
                }
                int Max = 0;
                for (int j = l + 1; j < r; ++j) {
                    ++num[a[j]];
                    Max = max(Max, num[a[j]]);
                }
                ans = max(ans, Max + 2 * cnt);
                --cnt;
                while (cnt > 0) {
                    while (a[l - 1] != i) {
                        ++num[a[l]];
                        Max = max(Max, num[a[l]]);
                        --l;
                    }
                    ++num[a[l]];
                    Max = max(Max, num[a[l]]);
                    --l;
                    while (a[r + 1] != i) {
                        ++num[a[r]];
                        Max = max(Max, num[a[r]]);
                        ++r;
                    }
                    ++num[a[r]];
                    Max = max(Max, num[a[r]]);
                    ++r;
                    ans = max(ans, Max + 2 * cnt);
                    --cnt;
                }
            }
        }
        cout << max(ans, 1) << '\n';
    }

    return 0;
}