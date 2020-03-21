#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e2 + 5;

int T, n, m, in[maxn];
vector<int> g[maxn], res;

inline void init() {
    for (int i = 1; i <= n; ++i) g[i].clear();
}

bool test(int x) {
    queue<int> q;
    res.clear();
    for (int i = 1; i <= n; ++i) in[i] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j : g[i]) ++in[j];
    for (int i = 1; i <= n; ++i)
        if (!in[i]) q.push(i);
    while (q.size()) {
        int f = q.front();
        q.pop();
        res.push_back(f);
        for (int i : g[f]) {
            --in[i];
            if (!in[i]) q.push(i);
        }
    }
    if (in[x] == 1) {
        q.push(x);
        in[x]--;
    }
    while (q.size()) {
        int f = q.front();
        q.pop();
        res.push_back(f);
        for (int i : g[f])
            if (i != x) {
                in[i]--;
                if (!in[i]) q.push(i);
            }
    }
    return res.size() == n;
}

void solve() {
    for (int i = 1; i <= n; ++i)
        if (test(i)) {
            cout << "Yes\n";
            return;
        }
    cout << "No\n";
}

int main() {
#ifdef DEBUG
    freopen("8.in", "r", stdin);
    freopen("8.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; ++i) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }
        solve();
    }

    return 0;
}