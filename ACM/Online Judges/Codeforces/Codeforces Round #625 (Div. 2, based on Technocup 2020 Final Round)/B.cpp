#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;
constexpr int maxval = 4e5 + 5;

int n;
ll a[maxn];
map<ll, ll> m;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) m[a[i] - i] += a[i];
    ll _max = 0;
    for (auto i = m.begin(); i != m.end(); ++i) _max = max(_max, i->second);
    cout << _max << '\n';

    return 0;
}