#include <assert.h>

#include <algorithm>
#include <iostream>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("./SUSTech/CS203/2020Spring/Quiz 1/A/Input/test6.in", "r", stdin);
    freopen("./SUSTech/CS203/2020Spring/Quiz 1/A/Output/test6.out", "w",
            stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    assert(T <= 100);
    while (T--) {
        cin >> n;
        assert(n <= 1000);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            assert(a[i] <= 1000000);
            if (a[i] != a[i - 1]) cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}