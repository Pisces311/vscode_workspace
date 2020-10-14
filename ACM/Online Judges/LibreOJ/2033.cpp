#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

struct Node {
    int maxlen, fail;
    map<int, int> ma;
};

ll ans = 0;

struct SAM {
    int sz, last;
    Node node[maxn << 1];

    SAM() { sz = last = 1; }

    void extend(int id) {
        int cur = ++sz;
        node[cur].maxlen = node[last].maxlen + 1;
        int p;
        for (p = last; p && !node[p].ma[id]; p = node[p].fail)
            node[p].ma[id] = cur;
        if (!p)
            node[cur].fail = 1;
        else {
            int q = node[p].ma[id];
            if (node[q].maxlen == node[p].maxlen + 1)
                node[cur].fail = q;
            else {
                int clone = ++sz;
                node[clone] = node[q];
                node[clone].maxlen = node[p].maxlen + 1;
                for (; p && node[p].ma[id] == q; p = node[p].fail)
                    node[p].ma[id] = clone;
                node[cur].fail = node[q].fail = clone;
            }
        }
        last = cur;
        ans += node[cur].maxlen - node[node[cur].fail].maxlen;
    }
} sam;

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
        int x;
        cin >> x;
        sam.extend(x);
        cout << ans << '\n';
    }

    return 0;
}