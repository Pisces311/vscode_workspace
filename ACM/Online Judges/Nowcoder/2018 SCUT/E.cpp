#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int N, Q;
string str[maxn];
int nxt[maxn];

void get_next(string& p) {
    nxt[0] = 0;
    int plen = p.size();
    for (int q = 1, k = 0; q < plen; ++q) {
        while (k > 0 && p[q] != p[k]) k = nxt[k - 1];
        if (p[q] == p[k]) ++k;
        nxt[q] = k;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> str[i];
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        string t = str[v] + "*" + str[u];
        get_next(t);
        cout << nxt[t.size() - 1] << '\n';
    }

    return 0;
}