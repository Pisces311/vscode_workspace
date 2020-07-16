#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int t;
int c[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for (int i = 1; i <= t; ++i) cin >> c[i];
    int cnt = 0;
    for (int i = 1; i <= t; ++i)
        if (c[i] <= 35) ++cnt;
    cout << cnt << '\n';

    return 0;
}