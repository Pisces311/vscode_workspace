#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

struct Node {
    int maxlen, fail;
    int ch[26];
};

struct SAM {
    int sz, last;
    Node node[maxn << 1];

    SAM() { sz = last = 1; }

    void extend(int id) {
        int cur = ++sz;
        node[cur].maxlen = node[last].maxlen + 1;
        int p;
        for (p = last; p && !node[p].ch[id]; p = node[p].fail)
            node[p].ch[id] = cur;
        if (!p)
            node[cur].fail = 1;
        else {
            int q = node[p].ch[id];
            if (node[q].maxlen == node[p].maxlen + 1)
                node[cur].fail = q;
            else {
                int clone = ++sz;
                node[clone] = node[q];
                node[clone].maxlen = node[p].maxlen + 1;
                for (; p && node[p].ch[id] == q; p = node[p].fail)
                    node[p].ch[id] = clone;
                node[cur].fail = node[q].fail = clone;
            }
        }
        last = cur;
    }
} sam;