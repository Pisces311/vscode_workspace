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
    int n = 1e4;
    cout << n << '\n';
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt > 0) {
            int op = rint(1, 2);
            if (op == 1) {
                ++cnt;
                cout << op << ' ' << rint(1, 1e3) << '\n';
            } else {
                --cnt;
                cout << op << '\n';
            }
        } else {
            ++cnt;
            cout << 1 << ' ' << rint(1, 1e3) << '\n';
        }
    }

    return 0;
}