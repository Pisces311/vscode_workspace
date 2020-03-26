#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int main() {
#ifdef DEBUG
    freopen("./SUSTech/CS203/2020Spring/Quiz 1/C/Input/test1.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    int n = 1e6, m = 1e6;
    cout << n << ' ' << m << '\n';
    while (n--) cout << rint(0, 1e6) << ' ';
    int sz = n;
    cout << '\n';
    while (m--) {
        int op = rint(1, 3);
        if (op == 1) {
            cout << "P " << rint(0, 1e6) << '\n';
            sz++;
        } else if (op == 2) {
            if (sz) {
                cout << "R\n";
                sz--;
            } else
                m++;
        } else
            cout << "Q\n";
    }

    return 0;
}