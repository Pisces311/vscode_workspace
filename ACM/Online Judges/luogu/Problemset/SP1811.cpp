#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 25e4 + 5;

struct Node {
    int maxlen, fail;
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
        for (p = last; p && !node[p].trans[id]; p = node[p].fail)
            node[p].trans[id] = cur;
        if (!p)
            node[cur].fail = 1;
        else {
            int q = node[p].trans[id];
            if (node[q].maxlen == node[p].maxlen + 1)
                node[cur].fail = q;
            else {
                int clone = ++sz;
                node[clone] = node[q];
                node[clone].maxlen = node[p].maxlen + 1;
                for (; p && node[p].trans[id] == q; p = node[p].fail)
                    node[p].trans[id] = clone;
                node[cur].fail = node[q].fail = clone;
            }
        }
        last = cur;
    }
} sam;

int slen, tlen;
char s[maxn], t[maxn];

int cal() {
    int ans = 0, p = 1, l = 0;
    for (int i = 0; i < tlen; ++i) {
        int id = t[i] - 'a';
        if (sam.node[p].trans[id]) {
            p = sam.node[p].trans[id];
            ++l;
        } else {
            for (; p && !sam.node[p].trans[id]; p = sam.node[p].fail)
                ;
            if (!p) {
                l = 0;
                p = 1;
            } else {
                l = sam.node[p].maxlen + 1;
                p = sam.node[p].trans[id];
            }
        }
        ans = max(ans, l);
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

    cin >> s >> t;
    slen = strlen(s), tlen = strlen(t);
    for (int i = 0; i < slen; ++i) sam.extend(s[i] - 'a');
    cout << cal() << '\n';

    return 0;
}