#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int T, n, m;
int a[maxn], p[maxn];

struct SegTreeNode {
    int val;
} t[maxn << 2];

void pushUp(int o, int l, int r) {
    t[o].val = max(t[o << 1].val, t[o << 1 | 1].val);
}

void build(int o, int arr[], int l, int r) {
    if (l == r) {
        t[o].val = arr[l];
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, arr, l, mid);
        build(o << 1 | 1, arr, mid + 1, r);
        pushUp(o, l, r);
    }
}

int query(int o, int l, int r, int t1, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int ans = 0;
    if (mid >= k && t[o << 1].val > t1) ans = query(o << 1, l, mid, t1, k);
    if (ans) return ans;
    if (t[o << 1 | 1].val > t1) return query(o << 1 | 1, mid + 1, r, t1, k);
    return 0;
}

void update(int o, int l, int r, int pos) {
    if (r < pos || pos < l) return;
    if (pos <= l && r <= pos) {
        t[o].val += inf;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, pos);
    update(o << 1 | 1, mid + 1, r, pos);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            p[a[i]] = i;
        }
        p[n + 1] = n + 1;
        build(1, p, 1, n + 1);
        int LastAns = 0;
        while (m--) {
            int opt, t1, t2;
            cin >> opt;
            if (opt == 1) {
                cin >> t1;
                t1 ^= LastAns;
                update(1, 1, n + 1, a[t1]);
            } else {
                cin >> t1 >> t2;
                t1 ^= LastAns;
                t2 ^= LastAns;
                cout << (LastAns = query(1, 1, n + 1, t1, t2)) << '\n';
            }
        }
    }

    return 0;
}