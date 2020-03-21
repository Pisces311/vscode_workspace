#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

struct node {
    int d, h, dif;
    bool operator<(const node& a) const { return dif > a.dif; }
} a[maxn];

int t, n;
ll x;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> x;
        int ma = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].d >> a[i].h;
            a[i].dif = a[i].d - a[i].h;
            ma = max(ma, a[i].d);
        }
        sort(a + 1, a + n + 1);
        x -= ma;
        if (x <= 0)
            cout << 1 << '\n';
        else {
            if (a[1].dif <= 0) {
                cout << -1 << '\n';
                continue;
            }
            if (x % a[1].dif == 0)
                cout << x / a[1].dif + 1 << '\n';
            else
                cout << x / a[1].dif + 2 << '\n';
        }
    }

    return 0;
}