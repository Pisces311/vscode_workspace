#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("8.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));
    int n = 200000, m = 400000;
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n - 1; ++i)
        cout << i << ' ' << i + 1 << ' ' << rint(1, 2) << '\n';
    for (int i = n; i <= m; ++i) {
        int x = rint(1, n), y = rint(1, n);
        cout << x << ' ' << y << ' ' << rint(1, 2) << '\n';
    }

    return 0;
}