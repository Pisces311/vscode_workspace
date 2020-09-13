#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, N, A, B;
int a[maxn], b[maxn], c[maxn], sz[maxn];
vector<int> g[maxn];

inline void init() {
    for (int i = 1; i <= N; ++i) g[i].clear();
    fill(a + 1, a + N + 1, 0);
    fill(b + 1, b + N + 1, 0);
    fill(sz + 1, sz + N + 1, 0);
}

void dfs(int u, int f) {
    int tot = 0;
    sz[u] = 1;
    for (int v : g[u]) {
        if (v != f) {
            dfs(v, u);
            tot += a[v];
            sz[u] += sz[v];
        }
    }
    a[u] = max(a[u], tot);
}

void dfs2(int u, int f, int mid) {
    c[u] = 1;
    for (int v : g[u]) {
        if (v != f) {
            dfs2(v, u, mid);
            c[u] += c[v];
        }
    }
    c[u] = min(c[u], mid - b[u]);
}

bool check(int mid) {
    dfs2(1, -1, mid);
    for (int i = 1; i <= N; ++i)
        if (a[i] > c[i]) return false;
    return a[1] <= mid && mid <= c[1];
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
        init();
        for (int i = 1; i < N; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cin >> A;
        for (int i = 1; i <= A; ++i) {
            int x, y;
            cin >> x >> y;
            a[x] = max(a[x], y);
        }
        cin >> B;
        for (int i = 1; i <= B; ++i) {
            int x, y;
            cin >> x >> y;
            b[x] = max(b[x], y);
        }
        dfs(1, -1);
        int l = 0, r = N, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}