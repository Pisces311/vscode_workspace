#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

int n, m;
int a[maxn];
int Max[maxn][20];

void init() {
    for (int i = 1; i <= n; ++i) Max[i][0] = a[i];
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int qmax(int l, int r) {
    int k = (log(double(r - l + 1)) / log((double)2));
    return max(Max[l][k], Max[r - (1 << k) + 1][k]);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    init();
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << qmax(l, r) << '\n';
    }

    return 0;
}