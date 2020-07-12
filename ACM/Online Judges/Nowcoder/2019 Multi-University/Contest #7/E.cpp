#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 4e5 + 5;

struct SegTreeNode {
    ll num, lazy;
} t[maxn << 4];

int n, cnt = 0;
ll A1, B1, C1, M1, A2, B2, C2, M2;
ll x[maxn], y[maxn], L[maxn], R[maxn];
ll dc[maxn << 1];

void pushdown(int l, int r, int o) {
    if (t[o].lazy != 0) {
        int mid = (l + r) >> 1;
        t[o << 1].num += (dc[mid] - dc[l]) * t[o].lazy;
        t[o << 1 | 1].num += (dc[r] - dc[mid]) * t[o].lazy;
        t[o << 1].lazy += t[o].lazy;
        t[o << 1 | 1].lazy += t[o].lazy;
        t[o].lazy = 0;
    }
}

void update(int L, int R, int l, int r, int o) {
    if (L <= l && r - 1 <= R) {
        ++t[o].lazy;
        t[o].num += dc[r] - dc[l];
        return;
    }
    pushdown(l, r, o);
    int m = (l + r) >> 1;
    if (L < m) update(L, R, l, m, o << 1);
    if (R >= m) update(L, R, m, r, o << 1 | 1);
    t[o].num = t[o << 1].num + t[o << 1 | 1].num;
}

ll query(int o, int l, int r, ll k) {
    if (l + 1 == r) {
        ll lo = t[o].num / (dc[r] - dc[l]);
        return dc[l] + (k - 1) / lo;
    }
    pushdown(l, r, o);
    int m = (l + r) >> 1;
    if (t[o << 1].num >= k)
        return query(o << 1, l, m, k);
    else
        return query(o << 1 | 1, m, r, k - t[o << 1].num);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "dc", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> x[1] >> x[2] >> A1 >> B1 >> C1 >> M1;
    cin >> y[1] >> y[2] >> A2 >> B2 >> C2 >> M2;
    for (int i = 3; i <= n; ++i) {
        x[i] = (A1 * x[i - 1] + B1 * x[i - 2] + C1) % M1;
        y[i] = (A2 * y[i - 1] + B2 * y[i - 2] + C2) % M2;
    }
    for (int i = 1; i <= n; ++i) {
        L[i] = min(x[i], y[i]) + 1;
        R[i] = max(x[i], y[i]) + 1;
        dc[++cnt] = L[i];
        dc[++cnt] = R[i] + 1;
    }
    sort(dc + 1, dc + cnt + 1);
    int m = unique(dc + 1, dc + cnt + 1) - dc - 1;
    ll num = 0;
    for (int i = 1; i <= n; i++) {
        int l = lower_bound(dc + 1, dc + m + 1, L[i]) - dc;
        int r = lower_bound(dc + 1, dc + m + 1, R[i] + 1) - dc;
        update(l, r - 1, 1, m, 1);
        num += dc[r] - dc[l];
        cout << query(1, 1, m, (num + 1) / 2) << '\n';
    }

    return 0;
}