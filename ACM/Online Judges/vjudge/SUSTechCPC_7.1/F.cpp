#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct node {
    int x, y, v;
    bool operator<(const node& a) const { return x == a.x ? y < a.y : x < a.x; }
} a[maxn];

int T, N;
int dy[maxn];
map<int, int> my;

void deal(int* x, map<int, int>& m) {
    sort(x + 1, x + N + 1);
    int cnt = 0;
    x[0] = -1;
    for (int i = 1; i <= N; ++i)
        if (x[i] != x[i - 1]) m[x[i]] = ++cnt;
}

struct SegTreeNode {
    int val;
} t[maxn << 2];

void pushUp(int o, int l, int r) {
    t[o].val = max(t[o << 1].val, t[o << 1 | 1].val);
}

int query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[o].val;
    int mid = (l + r) >> 1;
    return max(query(o << 1, l, mid, ql, qr),
               query(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int p, int val) {
    if (r < p || p < l) return;
    if (p <= l && r <= p) {
        t[o].val = max(val, t[o].val);
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, p, val);
    update(o << 1 | 1, mid + 1, r, p, val);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> a[i].x >> a[i].y >> a[i].v;
            dy[i] = a[i].y;
        }
        deal(dy, my);
        sort(a + 1, a + N + 1);
        memset(t, 0, sizeof(t));
        int last = 1;
        for (int i = 1; i <= N; ++i) {
            while (a[last].x != a[i].x) {
                update(1, 1, N, my[a[last].y], a[last].v);
                ++last;
            }
            a[i].v += query(1, 1, N, 1, my[a[i].y] - 1);
        }
        int ans = 0;
        for (int i = 1; i <= N; ++i) ans = max(ans, a[i].v);
        cout << ans << '\n';
    }

    return 0;
}