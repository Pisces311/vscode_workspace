#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

struct TrieTreeNode {
    int son[26], cnt, fail;
} trie[maxn];

int T, n, m, tot;
char s[maxn];
queue<int> q;
vector<string> evidence;

inline void init() {
    tot = 1;
    evidence.clear();
    memset(trie, 0, sizeof(trie));
}

void insert(char* s) {
    int u = 1, len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int v = s[i] - 'a';
        if (!trie[u].son[v]) trie[u].son[v] = ++tot;
        u = trie[u].son[v];
    }
    ++trie[u].cnt;
}

void get_fail() {
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

int query(string& s) {
    int u = 1, ans = 0;
    for (char ch : s) {
        int v = ch - 'a';
        int k = trie[u].son[v];
        while (k > 1 && trie[k].cnt != -1) {
            ans += trie[k].cnt;
            k = trie[k].fail;
        }
        u = trie[u].son[v];
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        init();
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            string str;
            cin >> str;
            evidence.push_back(str);
        }
        for (int i = 1; i <= m; ++i) {
            cin >> s;
            insert(s);
        }
        get_fail();
        for (string i : evidence) cout << query(i) << '\n';
    }

    return 0;
}