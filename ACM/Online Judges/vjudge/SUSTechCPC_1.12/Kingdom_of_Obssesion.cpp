#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

int T, n, s, st;
bool vis[maxn];
int cx[maxn], cy[maxn];
int edge[maxn][maxn];

int line(int u) {
    for (int v = 1; v <= min(s, n); ++v) {
        if (edge[u][v] && !vis[v]) {
            vis[v] = true;
            if (cy[v] == -1 || line(cy[v])) {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungary() {
    int sum = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for (int i = 1; i <= min(s, n); ++i) {
        if (cx[i] == -1) {
            memset(vis, false, sizeof(vis));
            sum += line(i);
        }
    }
    return sum;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    int cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        cin >> n >> s;
        st = max(n + 1, s + 1);
        if (n + s - st > 1e3) {
            cout << "No\n";
            continue;
        }
        memset(edge, 0, sizeof(edge));
        for (int i = st; i <= n + s; ++i) {
            for (int j = 1; j <= min(n, s); ++j) {
                if (i % j == 0) edge[i - st + 1][j] = 1;
            }
        }
        cout << (hungary() == min(s, n) ? "Yes" : "No") << '\n';
    }

    return 0;
}