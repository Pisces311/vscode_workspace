#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, nr, ng, nb;
ll r[maxn], g[maxn], b[maxn];

ll cal(int i, int j, int k, ll *aa, ll *bb, ll *cc) {
    if (j == 0 || k == 0) return 8e18;
    return (aa[i] - bb[j]) * (aa[i] - bb[j]) +
           (aa[i] - cc[k]) * (aa[i] - cc[k]) +
           (bb[j] - cc[k]) * (bb[j] - cc[k]);
}

ll solve(int x, int y, int z, ll *aa, ll *bb, ll *cc) {
    ll Min = 8e18;
    for (int i = 1, j = 1, k = 1; i <= x; ++i) {
        while (j < y && bb[j] < aa[i]) ++j;
        while (k < z && cc[k] < aa[i]) ++k;
        Min = min(Min, cal(i, j, k, aa, bb, cc));
        Min = min(Min, cal(i, j - 1, k - 1, aa, bb, cc));
        Min = min(Min, cal(i, j - 1, k, aa, bb, cc));
        Min = min(Min, cal(i, j, k - 1, aa, bb, cc));
    }
    return Min;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> nr >> ng >> nb;
        for (int i = 1; i <= nr; ++i) cin >> r[i];
        sort(r + 1, r + nr + 1);
        for (int i = 1; i <= ng; ++i) cin >> g[i];
        sort(g + 1, g + ng + 1);
        for (int i = 1; i <= nb; ++i) cin >> b[i];
        sort(b + 1, b + nb + 1);
        ll Min = 8e18;
        Min = min(Min, solve(nr, ng, nb, r, g, b));
        Min = min(Min, solve(ng, nb, nr, g, b, r));
        Min = min(Min, solve(nb, nr, ng, b, r, g));
        cout << Min << '\n';
    }

    return 0;
}