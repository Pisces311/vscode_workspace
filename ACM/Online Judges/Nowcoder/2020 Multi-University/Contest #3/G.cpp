#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 8e5 + 5;

int n, m;
int fa[maxn];
list<int> g[maxn << 1];

inline void init() {
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        g[i].clear();
    }
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int q;
        cin >> q;
        while (q--) {
            int o;
            cin >> o;
            if (find(o) == o) {
                list<int> s;
                for (int i : g[o]) {
                    int y = find(i);
                    if (y != o) {
                        fa[y] = o;
                        s.splice(s.end(), g[y]);
                    }
                }
                swap(s, g[o]);
            }
        }
        for (int i = 0; i < n; ++i) cout << find(i) << " ";
        cout << '\n';
    }

    return 0;
}