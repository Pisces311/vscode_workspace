#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e3 + 5;

int t, n;
int a[maxn], cnt[maxn];
vector<int> ans;

inline void init() {
    ans.clear();
    memset(cnt, 0, sizeof(cnt));
}

bool check() {
    for (int i = 1; i < n; ++i)
        if (a[i + 1] < a[i]) return false;
    return true;
}

int find_MEX() {
    for (int i = 0; i <= 2 * n; ++i)
        if (!cnt[i]) return i;
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
            ++cnt[a[i]];
        }
        while (!check()) {
            int MEX = find_MEX();
            if (MEX >= n) {
                for (int i = 1; i <= n; ++i) {
                    if (a[i] != i - 1) {
                        --cnt[a[i]];
                        ++cnt[MEX];
                        a[i] = MEX;
                        ans.push_back(i);
                        break;
                    }
                }
            } else {
                --cnt[a[MEX + 1]];
                ++cnt[MEX];
                a[MEX + 1] = MEX;
                ans.push_back(MEX + 1);
            }
        }
        cout << ans.size() << '\n';
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}