#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e6 + 5;

struct TrieTreeNode {
    int son[26], cnt, fail;
    void init() {
        cnt = fail = 0;
        memset(son, 0, sizeof(son));
    }
} trie[1005 * 55];

int n, tot = 1;
char virus[1005][50];
char s[maxn];
queue<int> q;
int ans[1005];

inline void init() {
    for (int i = 0; i <= tot; ++i) trie[i].init();
    tot = 1;
    memset(ans, 0, sizeof(ans));
}

void insert(char* s, int id) {
    int u = 1, len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int v = s[i] - 'A';
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
        int v = s[i] - 'A', k;
        if (0 <= v && v < 26)
            k = trie[u].son[v];
        else
            k = 1;
        while (k > 1) {
            ans[trie[k].cnt] += 1;
            k = trie[k].fail;
        }
        if (0 <= v && v < 26)
            u = trie[u].son[v];
        else
            u = 1;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        init();
        for (int i = 1; i <= n; ++i) {
            cin >> virus[i];
            insert(virus[i], i);
        }
        getFail();
        cin >> s;
        query(s);
        for (int i = 1; i <= n; ++i)
            if (ans[i]) cout << virus[i] << ": " << ans[i] << '\n';
    }

    return 0;
}