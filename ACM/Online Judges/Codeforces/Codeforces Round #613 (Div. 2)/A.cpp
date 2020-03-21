#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n;
char s[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> (s + 1);
    int cntl = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'L') ++cntl;
    }
    int cntr = n - cntl;
    int ans = cntl + cntr + 1;
    cout << ans << '\n';

    return 0;
}