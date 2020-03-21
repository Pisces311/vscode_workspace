#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct point {
    int x, y;
} a[maxn];

int n;

int check(int x) { return x > n ? 1 : x; }

bool solve() {
    for (int i = 1; i <= n / 2; ++i) {
        if (abs(a[i].x - a[i + 1].x) !=
                abs(a[i + n / 2].x - a[check(i + n / 2 + 1)].x) ||
            abs(a[i].y - a[i + 1].y) !=
                abs(a[i + n / 2].y - a[check(i + n / 2 + 1)].y))
            return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    if (n & 1)
        cout << "No\n";
    else {
        if (solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}