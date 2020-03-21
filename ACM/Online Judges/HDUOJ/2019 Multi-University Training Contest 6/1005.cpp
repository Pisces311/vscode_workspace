#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

struct node {
    int x, y, w;
    bool operator<(const node& a) const { return x < a.x; }
} a[maxn];

int T, n;
int dcy[maxn], pos[maxn];
ll pre[maxn << 2], suf[maxn << 2], s[maxn << 2], v[maxn << 2];

void build(int x, int a, int b) {
    pre[x] = suf[x] = s[x] = v[x] = 0;
    if (a == b) {
        pos[a] = x;
        return;
    }
    int mid = (a + b) >> 1;
    build(x << 1, a, mid);
    build(x << 1 | 1, mid + 1, b);
}

void update(int x, int val) {
    x = pos[x];
    s[x] += val;
    if (s[x] > 0)
        pre[x] = suf[x] = v[x] = s[x];
    else
        pre[x] = suf[x] = v[x] = 0;
    for (x >>= 1; x; x >>= 1) {
        pre[x] = max(pre[x << 1], s[x << 1] + pre[x << 1 | 1]);
        suf[x] = max(suf[x << 1 | 1], s[x << 1 | 1] + suf[x << 1]);
        s[x] = s[x << 1] + s[x << 1 | 1];
        v[x] =
            max(max(v[x << 1], v[x << 1 | 1]), suf[x << 1] + pre[x << 1 | 1]);
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].x >> a[i].y >> a[i].w;
            dcy[i] = a[i].y;
        }
        sort(a + 1, a + n + 1);
        sort(dcy + 1, dcy + n + 1);
        int m = unique(dcy + 1, dcy + n + 1) - dcy - 1;
        for (int i = 1; i <= n; ++i)
            a[i].y = lower_bound(dcy + 1, dcy + m + 1, a[i].y) - dcy;
        ll ans = 0;
        int j, k;
        for (int i = 1; i <= n; ++i)
            if (i == 1 || a[i].x != a[i - 1].x) {
                build(1, 1, m);
                for (j = i; j <= n; j = k) {
                    for (k = j; k <= n && a[j].x == a[k].x; ++k)
                        update(a[k].y, a[k].w);
                    ans = max(ans, v[1]);
                }
            }
        cout << ans << '\n';
    }

    return 0;
}