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
    int T = 5;
    cout << T << '\n';
    while (T--) {
        int n = 50000, m = 50000, q = 50000;
        cout << n << ' ' << m << ' ' << q << '\n';
        for (int i = 1; i <= 2; ++i)
            for (int j = 1; j <= 25001; ++j)
                if (i != j) cout << i << ' ' << j << ' ' << rint(1, 10) << '\n';
        while (q--) cout << rint(30000, 50000) << '\n';
    }

    return 0;
}