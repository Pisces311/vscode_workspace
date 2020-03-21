#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

struct point {
    int x, v;
    bool operator<(const point& other) const {
        return v == other.v ? x < other.x : v < other.v;
    }
} p[maxn];

int n;
int getx[maxn];
ll c1[maxn], c2[maxn];
map<int, int> xmap;

int lowbit(int x) { return x & (-x); }

ll sum(int x, ll* c) {
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) ans += c[i];
    return ans;
}

ll getSum(int l, int r, ll* c) { return sum(r, c) - sum(l - 1, c); }

void update(int x, int val, ll* c) {
    for (int i = x; i <= n; i += lowbit(i)) c[i] += val;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i].x;
    for (int i = 1; i <= n; ++i) cin >> p[i].v;
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i) getx[i] = p[i].x;
    sort(getx + 1, getx + n + 1);
    for (int i = 1; i <= n; ++i) xmap[getx[i]] = i;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int num = getSum(1, xmap[p[i].x], c1);
        ll sum = getSum(1, xmap[p[i].x], c2);
        ans += 1ll * num * p[i].x - sum;
        update(xmap[p[i].x], 1, c1);
        update(xmap[p[i].x], p[i].x, c2);
    }
    cout << ans << '\n';

    return 0;
}