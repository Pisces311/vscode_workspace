#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e4 + 5;

int n;
int a[maxn];

bool check() {
    int sum = 0, exp = 2 * (n - 1);
    for (int i = 1; i <= n; i++) {
        sum += (exp - a[i]);
        if (sum < 0) return false;
        exp -= 2;
    }
    return !sum;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    while (cin >> T) {
        while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) cin >> a[i];
            sort(a + 1, a + n + 1, [](int &a, int &b) { return a > b; });
            if (check())
                cout << "T\n";
            else
                cout << "F\n";
        }
    }

    return 0;
}