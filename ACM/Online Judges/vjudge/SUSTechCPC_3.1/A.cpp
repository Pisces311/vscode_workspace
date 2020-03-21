#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 4e5 + 5;

struct SegTreeNode {
    set<int> cover;
} t[maxn << 2];

int n;
int opr[maxn], x[maxn], y[maxn];
int dc[maxn << 2], top = 0;
map<int, int> id;

int query(int o, int l, int r, int pos, int qx, int qy) {
    if (r < pos || pos < l) return 0;
    if (l <= pos && pos <= r) {
        for (int i : t[o].cover) {
            ll dis = 1ll * (qx - x[i]) * (qx - x[i]) +
                     1ll * (qy - y[i]) * (qy - y[i]);
            if (dis < 1ll * y[i] * y[i]) return i;
        }
    }
    if (l == r) return 0;
    int mid = (l + r) >> 1;
    return query(o << 1, l, mid, pos, qx, qy) +
           query(o << 1 | 1, mid + 1, r, pos, qx, qy);
}

void update(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].cover.insert(val);
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, ul, ur, val);
    update(o << 1 | 1, mid + 1, r, ul, ur, val);
}

void del(int o, int l, int r, int ul, int ur, int val) {
    if (r < ul || ur < l) return;
    if (ul <= l && r <= ur) {
        t[o].cover.erase(val);
        return;
    }
    int mid = (l + r) >> 1;
    del(o << 1, l, mid, ul, ur, val);
    del(o << 1 | 1, mid + 1, r, ul, ur, val);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> opr[i] >> x[i] >> y[i];
        if (opr[i] == 1) {
            dc[++top] = x[i] + y[i];
            dc[++top] = x[i] - y[i];
        }
    }
    sort(dc + 1, dc + top + 1);
    int cnt = unique(dc + 1, dc + top + 1) - dc - 1;
    for (int i = 1; i <= cnt; ++i) id[dc[i]] = i;
    for (int i = 1; i <= n; ++i) {
        if (opr[i] == 1)
            update(1, 1, cnt, id[x[i] - y[i]] + 1, id[x[i] + y[i]], i);
        else {
            int pos = lower_bound(dc + 1, dc + cnt + 1, x[i]) - dc;
            if (pos == cnt + 1)
                cout << "-1\n";
            else {
                int ret = query(1, 1, cnt, pos, x[i], y[i]);
                if (ret == 0)
                    cout << "-1\n";
                else {
                    cout << ret << '\n';
                    del(1, 1, cnt, id[x[ret] - y[ret]] + 1, id[x[ret] + y[ret]],
                        ret);
                }
            }
        }
    }

    return 0;
}