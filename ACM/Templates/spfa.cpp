#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5e2 + 5;
constexpr int inf = 0x3f3f3f3f;

struct node {
    int id, w;
};

int N;
vector<node> g[maxn];
bool in[maxn];  // 标记是否在队列中
int dis[maxn], cnt[maxn];

bool spfa(int S) {
    fill(dis, dis + N + 1, inf);
    fill(cnt, cnt + N + 1, 0);
    fill(in, in + N + 1, false);
    queue<int> q;
    dis[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in[u] = false;
        for (node v : g[u]) {
            if (dis[v.id] > dis[u] + v.w) {
                dis[v.id] = dis[u] + v.w;
                if (!in[v.id]) {
                    q.push(v.id);
                    in[v.id] = true;
                    if (++cnt[v.id] > N) return false;
                }
            }
        }
    }
    return true;
}