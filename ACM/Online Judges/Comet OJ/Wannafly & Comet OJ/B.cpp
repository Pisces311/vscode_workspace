#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n, k;
ll a[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (abs(a[i] - a[i - 1]) < k) {
            a[i] = 1e18;
            ++cnt;
        }
    }
    printf("%d", cnt);

    return 0;
}