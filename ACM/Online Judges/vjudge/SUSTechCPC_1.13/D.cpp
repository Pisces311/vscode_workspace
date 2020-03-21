#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

int n, ans = 0;
int a[maxn], one[maxn], two[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        one[i] = one[i - 1];
        two[i] = two[i - 1];
        if (a[i] == 1)
            ++one[i];
        else
            ++two[i];
    }
    ans = one[n];
    for (int i = 1; i <= n; ++i)
        ans = max(ans, one[i - 1] - one[0] + two[n] - two[i - 1]);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) continue;
        for (int j = i; j <= n; ++j) {
            if (a[j] == 2) continue;
            for (int k = i; k <= j; ++k) {
                int ones = one[i - 1] - one[0] + one[j] - one[k - 1];
                int twos = two[k] - two[i - 1] + two[n] - two[j - 1];
                ans = max(ans, ones + twos);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}