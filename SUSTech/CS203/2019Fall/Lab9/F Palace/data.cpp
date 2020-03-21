#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

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
        int n = rint(1, 2000);
        cout << n << '\n';
        for (int i = 1; i <= n; ++i) {
            int a = rint(1, 1000), b = rint(1, 1000), c = rint(1, 1000);
            cout << a << ' ' << b << ' ' << c << '\n';
        }
    }

    return 0;
}