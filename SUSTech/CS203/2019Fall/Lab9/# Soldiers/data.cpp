#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("test.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));
    int T = 10;
    cout << T << '\n';
    while (T--) {
        int n = rint(40000, 50000), m = rint(100000, 20000);
        cout << 2 * n << ' ' << m << '\n';
        while (m--) {
            int u = rint(1, n), v = rint(n + 1, 2 * n);
            cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}