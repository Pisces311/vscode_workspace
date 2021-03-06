#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

struct TrieTreeNode {
    int son[26], cnt, fail;
} trie[maxn];

int tot = 1;
char s[maxn];
queue<int> q;

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

// 返回模式串在文本串中出现的次数
int query(char* s) {
    int u = 1, ans = 0, len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int v = s[i] - 'a';
        int k = trie[u].son[v];
        while (k > 1 && trie[k].cnt != -1) {
            ans += trie[k].cnt, trie[k].cnt = -1;
            k = trie[k].fail;
        }
        u = trie[u].son[v];
    }
    return ans;
}