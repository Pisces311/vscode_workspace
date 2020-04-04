#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int t, n;
int a[maxn];
bool lok[maxn], rok[maxn];
bool vis[maxn];

inline void init() {
    for (int i = 1; i <= n; ++i) {
        lok[i] = rok[i] = false;
        vis[i] = false;
    }
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
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1, lptr = 0; i <= n; ++i) {
            vis[a[i]] = true;
            while (vis[lptr + 1]) ++lptr;
            if (lptr == i) lok[i] = true;
        }
        // for (int i = 1; i <= n; ++i) cout << lok[i] << ' ';
        // cout << endl;
        for (int i = 1; i <= n; ++i) vis[i] = false;
        for (int i = n, rptr = 0; i >= 1; --i) {
            vis[a[i]] = true;
            while (vis[rptr + 1]) ++rptr;
            if (rptr == n - i + 1) rok[i] = true;
        }
        // for (int i = 1; i <= n; ++i) cout << rok[i] << ' ';
        // cout << endl;
        int cnt = 0;
        for (int i = 1; i < n; ++i)
            if (lok[i] && rok[i + 1]) ++cnt;
        cout << cnt << '\n';
        for (int i = 1; i < n; ++i)
            if (lok[i] && rok[i + 1]) {
                cout << i << ' ' << n - i << '\n';
            }
    }

    return 0;
}