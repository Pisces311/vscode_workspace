#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int t, n, m, k;
int h[maxn];

bool solve() {
    for (int i = 1; i <= n - 1; ++i) {
        int tar = max(0, h[i + 1] - k);
        if (h[i] >= h[i + 1] - k)
            m += h[i] - tar;
        else {
            int need = max(0, tar - h[i]);
            if (need > m)
                return false;
            else
                m -= need;
        }
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) cin >> h[i];
        if (solve())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}