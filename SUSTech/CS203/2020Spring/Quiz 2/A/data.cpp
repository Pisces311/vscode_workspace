#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e4 + 5;

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }
double rdouble(int a, int b) { return (b - a) * rand() / double(RAND_MAX) + a; }

int fa[maxn];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
#ifdef DEBUG
    freopen("SUSTech/CS203/2020Spring/Quiz 2/A/Input/3.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    int T = 10;
    cout << T << '\n';
    while (T--) {
        int n = rint(1000, 2000);
        cout << n << '\n';
        for (int i = 2; i <= n; ++i) {
            int father = rint(1, i - 1);
            cout << i << ' ' << father << '\n';
        }
    }

    return 0;
}