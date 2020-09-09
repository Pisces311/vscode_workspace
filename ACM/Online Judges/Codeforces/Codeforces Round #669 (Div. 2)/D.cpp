#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e5 + 5;

int n;
int a[maxn], dis[maxn];
vector<int> g[maxn];

void build() {
    stack<int> stk;
    stk.push(1);
    for (int i = 2; i <= n; ++i) {
        int la = -(1 << 30);
        while (!stk.empty() && a[stk.top()] < a[i]) {
            if (a[stk.top()] != la) g[stk.top()].push_back(i);
            la = a[stk.top()];
            stk.pop();
        }
        if (!stk.empty()) g[stk.top()].push_back(i);
        stk.push(i);
    }
}

void bfs() {
    fill(dis + 1, dis + n + 1, 0);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u])
            if (!dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build();
    for (int i = 1; i <= n; ++i) a[i] *= -1;
    build();
    bfs();
    cout << dis[n] << '\n';

    return 0;
}