#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

set<pii> se;

int main() {
#ifdef DEBUG
    freopen("8.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));
    int T = 10;
    cout << T << '\n';
    while (T--) {
        se.clear();
        int n = rint(2, 500), m = rint(1, min(n * (n - 1), 100000));
        cout << n << ' ' << m << '\n';
        while (m--) {
            int u = rint(1, n), v = rint(1, n);
            if (u != v) {
                pii p = make_pair(u, v);
                if (se.find(p) != se.end())
                    ++m;
                else {
                    se.insert(p);
                    cout << u << ' ' << v << '\n';
                }
            } else
                ++m;
        }
    }

    return 0;
}