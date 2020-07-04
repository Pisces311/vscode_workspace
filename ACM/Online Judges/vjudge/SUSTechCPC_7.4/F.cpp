#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;
constexpr int inf = 0x3f3f3f3f;

struct house {
    int id, h;
    bool operator<(const house& a) const { return h < a.h; }
} h[maxn];

struct node {
    int id, w;
};

int T, N, D;
bool in[maxn];
int dis[maxn], cnt[maxn];
vector<node> g[maxn];

bool spfa(int S) {
    memset(dis, inf, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    memset(in, false, sizeof(in));
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

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> N >> D;
        for (int i = 1; i <= N; ++i) {
            g[i].clear();
            cin >> h[i].h;
            h[i].id = i;
        }
        for (int i = 1; i < N; ++i) g[i + 1].push_back({i, -1});
        sort(h + 1, h + N + 1);
        for (int i = 1; i < N; ++i) {
            int u = h[i].id, v = h[i + 1].id;
            if (u > v) swap(u, v);
            g[u].push_back({v, D});
        }
        cout << "Case " << cas << ": ";
        int S = h[1].id, T = h[N].id;
        if (S > T) swap(S, T);
        if (spfa(S))
            cout << dis[T] << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}