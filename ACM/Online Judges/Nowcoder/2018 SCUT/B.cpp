#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct node {
    int l, r;
    int depth, fa;
    int cnt;
} t[maxn];

int n, q;
int pre[maxn];

int find(int x) { return x == pre[x] ? x : pre[x] = find(pre[x]); }

void operation(int x, int y) {
    int u = x, v = y;
    while (u != v) {
        if (t[u].depth < t[v].depth) swap(u, v);
        ++t[u].cnt;
        if (t[u].cnt == 1)
            t[u].l = min(x, y), t[u].r = max(x, y);
        else
            pre[u] = t[u].fa;
        u = find(t[u].fa);
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        for (int i = 1; i < n; ++i) {
            cin >> t[i].fa;
            t[i].depth = t[t[i].fa].depth + 1;
            t[i].cnt = 0;
            pre[i] = i;
        }
        cin >> q;
        while (q--) {
            char op;
            cin >> op;
            if (op == 'R') {
                int u, v;
                cin >> u >> v;
                operation(u, v);
            } else {
                int u;
                cin >> u;
                if (t[u].cnt == 0)
                    cout << "Not yet\n";
                else if (t[u].cnt == 1)
                    cout << t[u].l << ' ' << t[u].r << '\n';
                else
                    cout << "Many times\n";
            }
        }
    }

    return 0;
}