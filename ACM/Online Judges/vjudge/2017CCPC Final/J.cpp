#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e3 + 5;
constexpr int inf = 0x3f3f3f3f;

struct node {
    int id, w;
};

int N, M, X;
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

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case #" << cas << ": ";
        cin >> N >> M >> X;
        for (int i = 1; i <= N; ++i) g[i].clear();
        for (int i = 1; i < N; ++i) g[i + 1].push_back({i, -1});
        for (int i = 1; i <= N; ++i) g[0].push_back({i, 0});
        for (int i = 1; i <= M; ++i) {
            int A, B, C, D;
            cin >> A >> B >> C >> D;
            if (A == B && C == D) {
                g[A].push_back({C, X});
                g[C].push_back({A, -X});
            } else {
                g[B].push_back({C, X - 1});
                g[D].push_back({A, -X - 1});
            }
        }
        if (spfa(0)) {
            for (int i = 2; i <= N; ++i) cout << dis[i] - dis[i - 1] << ' ';
            cout << '\n';
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}