#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;
constexpr int inf = 0x3f3f3f3f;

int n;
int a[maxn], stk[maxn];

int solve(int l, int r) {
    int top = 0;
    for (int i = l; i <= r; ++i) {
        if (!top || a[i] > stk[top])
            stk[++top] = a[i];
        else {
            int p = lower_bound(stk + 1, stk + top + 1, a[i]) - stk;
            stk[p] = a[i];
        }
    }
    return top;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i + n] = a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, solve(i, i + n - 1));
    cout << n - ans << '\n';

    return 0;
}