#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int n;
int a[maxn], p[maxn], val[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) val[i] = a[i] - p[i];
        int has = val[0], ans = val[0], pile = 0;
        for (int i = 0, j = 0; i < n; has -= val[i], ++i) {
            while (has >= 0 && j < i + n) {
                ++j;
                has += val[j % n];
                if (has > ans) {
                    ans = has;
                    pile = i;
                }
            }
        }
        cout << pile << '\n';
    }

    return 0;
}
/*
5
4 6 2 8 4
1 5 7 9 2
*/