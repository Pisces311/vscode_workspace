#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int n;
ll a[maxn], pre[maxn];
ll cur = 0, l = 0, ret = 0;
map<ll, ll> m;

inline void init() { m.clear(); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    m[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        cur += a[i];
        if (m.find(cur) != m.end()) {
            l = m[cur] + 1;
            cur = pre[i] - pre[l];
            init();
            m[0] = l;
        }
        ret += i - l;
        m[cur] = i;
    }
    cout << ret << '\n';

    return 0;
}