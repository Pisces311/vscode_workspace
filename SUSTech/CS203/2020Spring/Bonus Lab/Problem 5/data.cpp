#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("test.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    int t = 10;
    cout << t << '\n';
    while (t--) {
        int n = rint(500, 1000), m = rint(1e3, 2e3), S = 1, T = n;
        cout << n << ' ' << m << ' ' << S << ' ' << T << '\n';
        for (int i = 1; i <= m; ++i) {
            int u = rint(1, n), v = rint(1, n);
            cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}