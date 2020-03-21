#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("5.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));
    int T = 10;
    cout << T << '\n';
    while (T--) {
        int n = rint(1, 100000), m = rint(1, 100000);
        cout << n << ' ' << m << '\n';
        for (int i = 1; i <= n; ++i) {
            int a = rint(0, 1000000000), b = rint(0, 1000000000);
            cout << a << ' ' << b << '\n';
        }
        for (int i = 1; i <= m; ++i) {
            int u = rint(1, n - 1), v = rint(u + 1, n);
            cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}