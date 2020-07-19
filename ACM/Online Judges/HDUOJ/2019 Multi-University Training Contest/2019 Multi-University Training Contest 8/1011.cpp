#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

struct node {
    int a, b;
} a[maxn];

int T, n;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i].a >> a[i].b;
        ll ans = 0, res = 0;
        int i, j;
        for (i = 1, j = n; i <= n && j >= 1; ++i) {
            while (a[i].a && j >= 1) {
                if (i != j) {
                    if (!res) {
                        if (a[j].b >= a[i].a) {
                            a[j].b -= a[i].a;
                            ans += a[i].a;
                            break;
                        } else {
                            a[i].a -= a[j].b;
                            ans += a[j].b;
                            --j;
                        }
                    } else {
                        if (res >= a[i].a) {
                            res -= a[i].a;
                            ans += a[i].a;
                            break;
                        } else {
                            a[i].a -= res;
                            ans += res;
                            res = 0;
                        }
                    }
                } else {
                    res = a[j].b;
                    --j;
                    while (a[i].a && j >= 1) {
                        if (a[j].b >= a[i].a) {
                            a[j].b -= a[i].a;
                            ans += a[i].a;
                            a[i].a = 0;
                        } else {
                            a[i].a -= a[j].b;
                            ans += a[j].b;
                            --j;
                        }
                    }
                }
            }
        }
        if (j == 0 && i != n + 1)
            for (; i <= n; ++i) {
                if (a[i].a <= res) {
                    res -= a[i].a;
                    ans += a[i].a;
                } else {
                    ans += res;
                    break;
                }
            }
        cout << ans << '\n';
    }

    return 0;
}