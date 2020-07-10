#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct EDGE {
    int v, next;
    string w;
} edge[maxn];

int T, N;
int towards[maxn], head[maxn], parent[maxn];
bool vis[maxn];
queue<int> q;
string words[maxn];

void init() {
    memset(head, 0, sizeof(head));
    memset(parent, -1, sizeof(parent));
    memset(vis, false, sizeof(vis));
}

inline int find(int x) {
    int pos;
    for (pos = x; parent[pos] > 0; pos = parent[pos])
        ;
    while (pos != x) {
        int tmp = parent[x];
        parent[x] = pos;
        x = tmp;
    }
    return pos;
}

inline void Union(int u, int v) {
    int tmp = parent[u] + parent[v];
    if (parent[u] > parent[v]) {
        parent[u] = v;
        parent[v] = tmp;
    } else {
        parent[v] = u;
        parent[u] = tmp;
    }
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
        init();
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> towards[i] >> words[i];
            edge[i] = {i, head[towards[i]], words[i]};
            head[towards[i]] = i;
        }
        for (int i = 1; i <= N; ++i)
            if (words[i] == "villager") Union(find(i), find(towards[i]));
        int ans = 0;
        for (int i = 1; i <= N; ++i)
            if (find(i) == find(towards[i]) && words[i] == "werewolf") {
                ++ans;
                q.push(towards[i]);
                vis[towards[i]] = true;
            }
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (int i = head[front]; i; i = edge[i].next) {
                int v = edge[i].v;
                if (!vis[v]) {
                    vis[v] = true;
                    if (edge[i].w == "villager") {
                        q.push(v);
                        ++ans;
                    }
                }
            }
        }
        cout << 0 << ' ' << ans << '\n';
    }

    return 0;
}