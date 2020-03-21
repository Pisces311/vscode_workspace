#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e1 + 5;

struct node {
    ll a, b, c;
    bool operator<(const node& a) const { return c * a.b < a.c * b; }
} a[maxn];

int T, n;
ll dp[100005];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].a;
    for (int i = 1; i <= n; ++i) cin >> a[i].b;
    for (int i = 1; i <= n; ++i) cin >> a[i].c;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = T; j >= a[i].c; --j) {
            dp[j] = max(dp[j], dp[j - a[i].c] + a[i].a - j * a[i].b);
        }
    }
    cout << *max_element(dp, dp + T + 1) << '\n';

    return 0;
}