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

    void init() { last = 1; }

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

ll ans = 0;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) sam.extend(s[i] - 'a');
        sam.init();
    }
    for (int i = 1; i <= sam.sz; ++i)
        ans += sam.node[i].maxlen - sam.node[sam.node[i].fail].maxlen;
    cout << ans << '\n';

    return 0;
}