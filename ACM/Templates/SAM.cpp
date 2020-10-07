#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

struct Node {
    int maxlen, fa;
    int trans[26];
};

struct SAM {
    int sz, last;
    Node node[maxn << 1];

    SAM() { sz = last = 1; }

    void extend(int id) {
        int cur = ++sz;
        node[cur].maxlen = node[last].maxlen + 1;
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
                for (; p && node[p].trans[id] == q; p = node[p].fa)
                    node[p].trans[id] = clone;
                node[cur].fa = node[q].fa = clone;
            }
        }
        last = cur;
    }
} sam;