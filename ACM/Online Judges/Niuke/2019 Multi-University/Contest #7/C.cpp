#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    int H, C, P, id;
    bool operator<(const node& a) const { return C < a.C; }
} a[maxn];

bool cmp(const node& a, const node& b) { return a.H < b.H; }

int n;

struct SegTreeNode {
    ll num, sum;
} t[maxn << 2];

void pushUp(int o, int l, int r) {
    t[o].num = t[o << 1].num + t[o << 1 | 1].num;
    t[o].sum = t[o << 1].sum + t[o << 1 | 1].sum;
}

void build(int o, int l, int r) {
    t[o].num = t[o].sum = 0;
    if (l == r) {
        return;
    } else {
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
    }
}

ll query(int o, int l, int r, ll num) {
    if (num <= 0) return 0;
    if (num >= t[o].num) return t[o].sum;
    if (l == r) return t[o].sum / t[o].num * num;
    int mid = (l + r) >> 1;
    return query(o << 1, l, mid, num) +
           query(o << 1 | 1, mid + 1, r, num - t[o << 1].num);
}

void update(int o, int l, int r, int id, int C, int P) {
    if (r < id || id < l) return;
    if (l == id && r == id) {
        t[o].num += P;
        t[o].sum += 1ll * C * P;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, id, C, P);
    update(o << 1 | 1, mid + 1, r, id, C, P);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) {
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].H >> a[i].C >> a[i].P;
            ans += 1ll * a[i].C * a[i].P;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) a[i].id = i;
        build(1, 1, n);
        sort(a + 1, a + n + 1, cmp);
        int j = 0;
        ll tot = 0, cur = a[1].P;
        ll res = ans - 1ll * a[1].C * a[1].P;
        for (int i = 2; i <= n; ++i) {
            if (i == n || a[i].H != a[i - 1].H) {
                ll tmp = query(1, 1, n, tot - (cur - 1)) + res;
                ans = min(ans, tmp);
                cur = a[i].P;
                if (i < n) {
                    while (j < i) {
                        update(1, 1, n, a[j].id, a[j].C, a[j].P);
                        tot += a[j].P;
                        j++;
                    }
                }
            } else
                cur += a[i].P;
            if (i < n) res -= 1ll * a[i].C * a[i].P;
        }
        cout << ans << '\n';
    }

    return 0;
}