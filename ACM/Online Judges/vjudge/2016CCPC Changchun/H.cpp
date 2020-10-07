#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int T, n, m, p;
int a[maxn];
int nxt[maxn];
vector<int> v, b;

void get_next(vector<int> &p) {
    nxt[0] = 0;
    int plen = p.size();
    for (int q = 1, k = 0; q < plen; ++q) {
        while (k > 0 && p[q] != p[k]) k = nxt[k - 1];
        if (p[q] == p[k]) ++k;
        nxt[q] = k;
    }
}

int KMP(vector<int> &s, vector<int> &p) {
    int slen = s.size(), plen = p.size();
    int cnt = 0;
    for (int i = 0, j = 0; i < slen; ++i) {
        while (j > 0 && p[j] != s[i]) j = nxt[j - 1];
        if (p[j] == s[i]) ++j;
        if (j == plen) {
            ++cnt;
            j = nxt[j - 1];
        }
    }
    return cnt;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> n >> m >> p;
        for (int i = 0; i < n; ++i) cin >> a[i];
        b.resize(m);
        for (int &i : b) cin >> i;
        get_next(b);
        int ans = 0;
        for (int i = 0; i < p; ++i) {
            v.clear();
            for (int j = i; j < n; j += p) v.push_back(a[j]);
            ans += KMP(v, b);
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }

    return 0;
}