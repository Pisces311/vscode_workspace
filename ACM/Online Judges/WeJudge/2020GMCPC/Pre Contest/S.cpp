#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

struct TrieTreeNode {
    int son[26];
    bool flag;
} trie[maxn];

int n, q, tot = 1;
string str;
set<string> s;

void insert(string str) {
    int u = 1, len = str.size();
    for (int i = 0; i < len; ++i) {
        int v = str[i] - 'a';
        if (!trie[u].son[v]) trie[u].son[v] = ++tot;
        u = trie[u].son[v];
    }
    trie[u].flag = true;
}

int exist(string str) {
    int u = 1, len = str.size();
    for (int i = 0; i < len; ++i) {
        int v = str[i] - 'a';
        if (!trie[u].son[v]) return -1;
        u = trie[u].son[v];
    }
    return u;
}

void dfs(int u) {
    if (s.size() == 50) return;
    if (trie[u].flag) s.insert(str);
    for (int i = 0; i < 26; ++i) {
        if (trie[u].son[i]) {
            char ch = 'a' + i;
            if (trie[u].son[i]) {
                str += ch;
                dfs(trie[u].son[i]);
                str.pop_back();
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        insert(str);
    }
    cin >> q;
    while (q--) {
        cin >> str;
        int ret = exist(str);
        if (ret == -1) {
            cout << str << '\n';
            insert(str);
        } else {
            s.clear();
            s.insert(str);
            dfs(ret);
            for (string i : s) cout << i << '\n';
        }
    }

    return 0;
}