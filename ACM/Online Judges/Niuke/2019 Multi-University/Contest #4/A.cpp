#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    int u, w;
};

int n, k, S;
int s[maxn];
bool vis[maxn], isst[maxn];
vector<int> g[maxn];

int bfs(int st, int flag) {
    int num = k;
    memset(vis, false, sizeof(vis));
    queue<node> q;
    q.push({st, 0});
    vis[st] = true;
    while (!q.empty()) {
        node f = q.front();
        q.pop();
        for (int i : g[f.u]) {
            if (vis[i])
                continue;
            else {
                vis[i] = true;
                if (isst[i]) {
                    --num;
                    if (num == 1 && flag == 1)
                        return i;
                    else if (num == 1)
                        return f.w + 1;
                }
                q.push({i, f.w + 1});
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &s[i]);
        isst[s[i]] = true;
    }
    S = bfs(s[1], 1);
    printf("%d\n", (bfs(S, 2) + 1) / 2);

    return 0;
}