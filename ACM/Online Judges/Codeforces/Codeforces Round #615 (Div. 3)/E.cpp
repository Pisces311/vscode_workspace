#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int n, m;
vector<int> a[maxn], b[maxn];
int c[maxn], d[maxn];
int pos[maxn], u[maxn], tt;

int solve(int n) {
    vector<int> cc(n);
    tt++;
    for (int i = 0; i < n; ++i) {
        pos[d[i]] = i;
        u[d[i]] = tt;
    }
    for (int i = 0; i < n; ++i) {
        if (u[c[i]] == tt) {
            cc[(i - pos[c[i]] + n) % n]++;
        }
    }
    int an = n;
    for (int i = 0; i < n; ++i) {
        an = min(an, n - cc[i] + i);
    }
    return an;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int now = 1;
    for (int i = 0; i < n; ++i) {
        a[i] = vector<int>(m);
        b[i] = vector<int>(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            b[i][j] = now++;
        }
    }
    int an = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            c[j] = a[j][i];
            d[j] = b[j][i];
        }
        an += solve(n);
    }
    cout << an << '\n';

    return 0;
}