#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e6 + 5;

int m, n = 0, head = 1, tail = 0;
int a[maxn], q[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m;
    int ans = 0;
    while (++n) {
        cin >> a[n];
        if (a[n] == -1) {
            cout << ans << '\n';
            break;
        }
        while (head <= tail && a[q[tail]] < a[n]) tail--;
        q[++tail] = n;
        while (head <= tail && q[head] <= n - m) head++;
        if (n >= m) ans ^= a[q[head]];
    }

    return 0;
}