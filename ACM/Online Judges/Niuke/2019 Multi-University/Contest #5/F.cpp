#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e3 + 5;

int n;
int a[maxn];
int l_v[maxn], r_v[maxn];
int l_cnt = 0, r_cnt = 0;
int le[maxn], ri[maxn];
int S[maxn], T[maxn];
vector<int> g[maxn];

bool match(int u) {
    S[u] = true;
    for (int v : g[u]) {
        if (!T[v]) {
            T[v] = true;
            if (le[v] == -1 || match(le[v])) {
                le[v] = u;
                ri[u] = v;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    memset(le, -1, sizeof(le));
    memset(ri, -1, sizeof(ri));
    int ans = 0;
    for (int i = 1; i <= l_cnt; i++) {
        memset(S, 0, sizeof(S));
        memset(T, 0, sizeof(T));
        if (match(i)) ans++;
    }
    return ans;
}

void max_set() {
    memset(S, 0, sizeof(S));
    memset(T, 0, sizeof(T));
    for (int i = 1; i <= l_cnt; i++)
        if (ri[i] == -1) match(i);
    for (int i = 1; i <= l_cnt; i++)
        if (S[i]) cout << l_v[i] << ' ';
    for (int i = 1; i <= r_cnt; i++)
        if (!T[i]) cout << r_v[i] << ' ';
    cout << '\n';
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (__builtin_popcount(a[i]) & 1)
            l_v[++l_cnt] = a[i];
        else
            r_v[++r_cnt] = a[i];
    for (int i = 1; i <= l_cnt; i++)
        for (int j = 1; j <= r_cnt; j++)
            if (__builtin_popcount(l_v[i] ^ r_v[j]) == 1) g[i].push_back(j);
    cout << n - hungary() << '\n';
    max_set();

    return 0;
}