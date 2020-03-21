#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

int T, n;
int a[maxn], b[maxn], c[maxn], dis[maxn], deg[maxn];
vector<int> g[maxn];

inline void init() {
    for (int i = 1; i <= n; ++i) g[i].clear();
    memset(deg, 0, sizeof(deg));
    memset(dis, 0, sizeof(dis));
}

void topo() {
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (!deg[i]) {
            q.push(i);
            dis[i] = c[i];
        }
    while (q.size()) {
        int front = q.front();
        q.pop();
        for (int i : g[front]) {
            --deg[i];
            dis[i] = max(dis[i], dis[front] + c[i]);
            if (!deg[i]) q.push(i);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
        init();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if ((a[i] < a[j] && b[i] < b[j]) ||
                    (a[i] < b[j] && b[i] < a[j])) {
                    g[j].push_back(i);
                    ++deg[i];
                }
        topo();
        cout << *max_element(dis + 1, dis + n + 1) << '\n';
    }

    return 0;
}