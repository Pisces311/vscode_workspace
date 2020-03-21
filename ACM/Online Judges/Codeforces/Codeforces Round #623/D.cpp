#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

struct cate {
    ll num, t;
    bool operator<(const cate& other) const { return t > other.t; }
} a[maxn];

int n;
set<ll> has;
map<ll, ll> fa;

ll find(ll x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].num;
        fa[a[i].num] = a[i].num;
    }
    for (int i = 1; i <= n; ++i) cin >> a[i].t;
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll cur = a[i].num;
        if (has.find(cur) != has.end()) {
            cur = find(cur);
            cur += 1;
            fa[cur] = cur;
            ans += (cur - a[i].num) * a[i].t;
        }
        has.insert(cur);
        if (has.find(cur - 1) != has.end()) fa[cur - 1] = cur;
        if (has.find(cur + 1) != has.end()) fa[cur] = cur + 1;
    }
    cout << ans << '\n';

    return 0;
}