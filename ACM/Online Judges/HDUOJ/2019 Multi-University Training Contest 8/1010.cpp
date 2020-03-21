#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    string s;
    int p, t;
    bool operator<(const node& a) const { return p == a.p ? t < a.t : p > a.p; }
} a[maxn];

int T, n, d, p, t;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> d;
        double line = n * 10.0 * d / 100;
        for (int i = 1; i <= n; ++i) cin >> a[i].s >> a[i].p >> a[i].t;
        if (line - (int)line == 0.5) {
            sort(a + 1, a + n + 1);
            cout << a[(int)(line + 0.5)].s << '\n';
        } else
            cout << "Quailty is very great" << '\n';
    }

    return 0;
}