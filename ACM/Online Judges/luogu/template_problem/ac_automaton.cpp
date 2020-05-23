#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

struct TrieTreeNode {
    int son[26], cnt, fail;
    void clear() {
        memset(son, 0, sizeof(son));
        cnt = fail = 0;
    }
} trie[155 * 75];

int n, tot;
char p[155][75], t[maxn];
int vis[155];
queue<int> q;

void init() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= tot; ++i) trie[i].clear();
    tot = 1;
}

void insert(char* s, int id) {
    int u = 1, len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int v = s[i] - 'a';
        if (!trie[u].son[v]) trie[u].son[v] = ++tot;
        u = trie[u].son[v];
    }
    trie[u].cnt = id;
}

void getFail() {
    for (int i = 0; i < 26; ++i) trie[0].son[i] = 1;
    trie[1].fail = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
            int v = trie[u].son[i];
            int ufail = trie[u].fail;
            if (v) {
                trie[v].fail = trie[ufail].son[i];
                q.push(v);
            } else {
                trie[u].son[i] = trie[ufail].son[i];
            }
        }
    }
}

// 返回模式串在文本串中出现的次数
void query(char* s) {
    int u = 1, len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int v = s[i] - 'a';
        int k = trie[u].son[v];
        while (k > 1) {
            ++vis[trie[k].cnt];
            k = trie[k].fail;
        }
        u = trie[u].son[v];
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n, n) {
        init();
        for (int i = 1; i <= n; ++i) {
            cin >> (p[i] + 1);
            insert(p[i] + 1, i);
        }
        getFail();
        cin >> (t + 1);
        query(t + 1);
        int Max = *max_element(vis + 1, vis + n + 1);
        cout << Max << '\n';
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == Max) {
                cout << (p[i] + 1) << '\n';
            }
        }
    }

    return 0;
}