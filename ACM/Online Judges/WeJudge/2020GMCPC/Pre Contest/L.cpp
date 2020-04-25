#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct fish {
    int id, val, beauty;
    bool operator<(const fish& a) const {
        return beauty == a.beauty ? id < a.id : beauty < a.beauty;
    }
} a[maxn], b[maxn];

int T, n;

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
        t[o].val = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, p, val);
    update(o << 1 | 1, mid + 1, r, p, val);
    pushUp(o, l, r);
}

int lis() {
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; ++i) b[i] = a[i];
    sort(b + 1, b + n + 1);
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (b[i].val > 0) {
            int q = query(1, 1, 2e4, 1, b[i].id);
            ret = max(ret, q + b[i].val);
            update(1, 1, 2e4, b[i].id, q + b[i].val);
        }
    }
    return ret;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case #" << cas << ": ";
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i].beauty;
        for (int i = 1; i <= n; ++i) {
            a[i].id = i;
            a[i].val = a[i].beauty / 10000;
            a[i].beauty %= 10000;
        }
        int ret1 = lis();
        for (int i = 1; i <= n; ++i) a[i].id = n - i + 1;
        int ret2 = lis();
        cout << max(ret1, ret2) << '\n';
    }

    return 0;
}