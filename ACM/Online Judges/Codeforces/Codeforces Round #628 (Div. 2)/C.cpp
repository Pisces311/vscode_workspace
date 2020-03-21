#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct Edge {
    int u, v;
} edge[maxn];

int n;
int in[maxn], out[maxn];
pair<int, int> ans;

pair<int, int> find() {
    int u = -1, v = -1;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 1) {
            if (u == -1)
                u = i;
            else if (v == -1) {
                v = i;
                break;
            }
        }
    }
    return make_pair(u, v);
}

int check() {
    for (int i = 1; i < n; ++i) {
        if (edge[i].u != ans.first && edge[i].u != ans.second &&
            in[edge[i].u] == 1) {
            out[i] = 2;
            return 2;
        } else if (edge[i].v != ans.first && edge[i].v != ans.second &&
                   in[edge[i].v] == 1) {
            out[i] = 2;
            return 2;
        }
    }
    return 1;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> edge[i].u >> edge[i].v;
        ++in[edge[i].u], ++in[edge[i].v];
    }
    ans = find();
    int cnt = check();
    bool flag = false;
    for (int i = 1; i < n; ++i) {
        if (out[i]) continue;
        if (edge[i].u == ans.first || edge[i].v == ans.first ||
            edge[i].u == ans.second || edge[i].v == ans.second) {
            if (!flag) {
                out[i] = 0;
                flag = true;
            } else
                out[i] = 1;
        } else
            out[i] = ++cnt;
    }
    for (int i = 1; i < n; ++i) cout << out[i] << '\n';

    return 0;
}