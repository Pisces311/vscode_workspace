#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int n, m;
int a[maxn], b[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(b + 1, b + m + 1);
    cout << a[n] << ' ' << b[m] << '\n';

    return 0;
}