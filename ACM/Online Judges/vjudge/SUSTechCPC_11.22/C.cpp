#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct Node {
    int maxlen, fail;
    int ch[26];
};

struct SAM {
    int sz, last;
    Node node[maxn << 1];

    void init() {
        sz = last = 1;
        memset(node[1].ch, 0, sizeof(node[1].ch));
    }

    void extend(int id) {
        int cur = ++sz;
        memset(node[cur].ch, 0, sizeof(node[cur].ch));
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

    bool dominate(string tmp) {
        int u = 1, len = tmp.size();
        int i = 0;
        while (i < len) {
            int id = tmp[i] - 'a';
            if (!node[u].ch[id]) return false;
            u = node[u].ch[id];
            ++i;
        }
        return true;
    }
} sam;

int N;
vector<string> str;

bool check() {
    for (string i : str) {
        if (!sam.dominate(i)) return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        str.resize(N);
        for (string &i : str) cin >> i;
        string s = str.front();
        for (string &i : str)
            if (i.size() > s.size()) s = i;
        sam.init();
        for (char i : s) sam.extend(i - 'a');
        if (check()) {
            cout << s << '\n';
        } else
            cout << "No\n";
    }

    return 0;
}