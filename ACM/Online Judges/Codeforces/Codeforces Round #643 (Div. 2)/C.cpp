#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int A, B, C, D;
ll a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> C >> D;
    for (int i = A; i <= B; ++i) {
        a[i + B]++;
        a[i + C + 1]--;
    }
    for (int i = 1; i < maxn; ++i) a[i] += a[i - 1];
    for (int i = 1; i < maxn; ++i) a[i] += a[i - 1];
    ll ans = 0;
    for (int i = C; i <= D; ++i) ans += a[maxn - 1] - a[i];
    cout << ans << '\n';

    return 0;
}