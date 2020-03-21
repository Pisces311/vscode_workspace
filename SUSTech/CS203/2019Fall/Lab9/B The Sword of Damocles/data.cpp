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
        int n = rint(1, 10000), m = rint(1, 10000), k = rint(1, 1000);
        cout << n << ' ' << m << ' ' << k << '\n';
        while (k--) {
            int x = rint(0, n), y = rint(0, m), s = rint(80, 120);
            cout << x << ' ' << y << ' ' << s << '\n';
        }
    }

    return 0;
}