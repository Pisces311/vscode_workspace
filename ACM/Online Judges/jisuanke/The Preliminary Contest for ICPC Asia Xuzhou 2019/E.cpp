#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e5 + 5;

struct node {
    int val, id;
    bool operator<(const node& a) const {
        return val == a.val ? id > a.id : val > a.val;
    }
} a[maxn];

int n, m;
int ans[maxn], t[maxn << 2];

void pushUp(int o, int l, int r) { t[o] = max(t[o << 1], t[o << 1 | 1]); }

int query(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[o];
    int mid = (l + r) >> 1;
    return max(query(o << 1, l, mid, ql, qr),
               query(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int pos, int val) {
    if (r < pos || pos < l) return;
    if (pos <= l && r <= pos) {
        t[o] += val;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, pos, val);
    update(o << 1 | 1, mid + 1, r, pos, val);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j < n && a[i].val + m <= a[j].val) {
            update(1, 1, n, a[j].id, a[j].id);
            ++j;
        }
        if (a[i].id == n)
            ans[a[i].id] = -1;
        else {
            int ret = query(1, 1, n, a[i].id + 1, n);
            if (ret == 0)
                ans[a[i].id] = -1;
            else
                ans[a[i].id] = ret - a[i].id - 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i];
        if (i != n) cout << ' ';
    }
    cout << '\n';

    return 0;
}