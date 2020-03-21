#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e4 + 5;

struct TrieTreeNode {
    int son[2], fail;
    bool flag;
} trie[maxn];

int n, tot = 1;
char s[maxn];
bool in[maxn], vis[maxn], ok = false;
queue<int> q;

void insert(char* s) {
    int u = 1, len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int v = s[i] - '0';
        if (!trie[u].son[v]) trie[u].son[v] = ++tot;
        u = trie[u].son[v];
    }
    trie[u].flag = true;
}

void getFail() {
    for (int i = 0; i < 2; ++i) trie[0].son[i] = 1;
    trie[1].fail = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 2; ++i) {
            int v = trie[u].son[i];
            int ufail = trie[u].fail;
            if (v) {
                trie[v].fail = trie[ufail].son[i];
                trie[v].flag |= trie[trie[ufail].son[i]].flag;
                q.push(v);
            } else {
                trie[u].son[i] = trie[ufail].son[i];
            }
        }
    }
}

void dfs(int u) {
    if (trie[u].flag || (vis[u] && !in[u])) return;
    if (in[u]) {
        ok = true;
        return;
    }
    vis[u] = in[u] = true;
    for (int i = 0; i < 2; ++i) {
        int v = trie[u].son[i];
        if (v) dfs(v);
    }
    in[u] = false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        insert(s);
    }
    getFail();
    dfs(1);
    if (ok) {
        cout << "TAK\n";
    } else {
        cout << "NIE\n";
    }

    return 0;
}