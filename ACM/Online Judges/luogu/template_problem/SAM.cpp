#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

struct Node {
    int maxlen, fa, cnt;
    int trans[26];
};

struct SAM {
    int sz, last;
    Node node[maxn << 1];

    SAM() { sz = last = 1; }

    void extend(int id) {
        int cur = ++sz;
        node[cur].maxlen = node[last].maxlen + 1;
        node[cur].cnt = 1;
        int p;
        for (p = last; p && !node[p].trans[id]; p = node[p].fa)
            node[p].trans[id] = cur;
        if (!p)
            node[cur].fa = 1;
        else {
            int q = node[p].trans[id];
            if (node[q].maxlen == node[p].maxlen + 1)
                node[cur].fa = q;
            else {
                int clone = ++sz;
                node[clone] = node[q];
                node[clone].maxlen = node[p].maxlen + 1;
                node[clone].fa = node[q].fa;
                node[clone].cnt = 0;
                for (; p && node[p].trans[id] == q; p = node[p].fa)
                    node[p].trans[id] = clone;
                node[cur].fa = node[q].fa = clone;
            }
        }
        last = cur;
    }
} sam;

char s[maxn];
vector<int> g[maxn << 1];
ll ans = 0;

void dfs(int u) {
    for (int v : g[u]) {
        dfs(v);
        sam.node[u].cnt += sam.node[v].cnt;
    }
    if (sam.node[u].cnt > 1)
        ans = max(ans, 1ll * sam.node[u].cnt * sam.node[u].maxlen);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) sam.extend(s[i] - 'a');
    for (int i = 2; i <= sam.sz; ++i) g[sam.node[i].fa].push_back(i);
    dfs(1);
    cout << ans << '\n';

    return 0;
}