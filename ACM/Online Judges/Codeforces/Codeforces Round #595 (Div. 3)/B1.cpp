#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e2 + 5;

int q, n;
int a[maxn];

int solve(int x) {
    int cur = a[x], day = 1;
    while (cur != x) {
        cur = a[cur];
        ++day;
    }
    return day;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cout << solve(i) << ' ';
        cout << '\n';
    }

    return 0;
}