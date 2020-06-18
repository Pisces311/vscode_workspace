#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

ll k;
int a[12];
char str[] = {"codeforces"};

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;
    ll ret = 1;
    int p = 0;
    for (int i = 0; i < 10; ++i) a[i] = 1;
    while (ret < k) {
        ret /= a[p];
        ++a[p];
        ret *= a[p];
        p = (p + 1) % 10;
    }
    for (int i = 0; i < 10; ++i)
        for (int j = 1; j <= a[i]; ++j) cout << str[i];
    cout << '\n';

    return 0;
}