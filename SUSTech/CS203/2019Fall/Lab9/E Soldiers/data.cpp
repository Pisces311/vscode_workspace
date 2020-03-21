#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("6.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));
    int T = 1;
    cout << T << '\n';
    while (T--) {
        int n = rint(2, 200000 - 1), m = rint(2 * n, 400000);
        cout << n << ' ' << m << '\n';
        while (m--) {
            int x = rint(1, n - 1), y = rint(x + 1, n);
            cout << y << ' ' << x << '\n';
        }
    }

    return 0;
}