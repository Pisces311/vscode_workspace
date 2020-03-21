#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 5;

int t, n;
int a[maxn];

bool check() {
    for (int i = 1; i <= n; ++i)
        if (a[i] < i - 1) return false;
    return true;
}

bool solve() {
    for (int i = n; i >= 1; --i)
        if (a[i] < n - i) return false;
    return true;
}

bool solve2() {
    int pos = -1, tmp = -1;
    a[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[i - 1]) {
            tmp = a[i];
            a[i] = a[i - 1] + 1;
        } else {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return true;
    else {
        a[pos - 1] = tmp;
    }
    for (int i = pos; i <= n; ++i) {
        if (a[i] >= a[i - 1]) {
            a[i] = a[i - 1] - 1;
            if (a[i] < 0) return false;
        }
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

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (check()) {
            cout << "Yes\n";
        } else {
            if (solve()) {
                cout << "Yes\n";
            } else {
                if (solve2()) {
                    cout << "Yes\n";
                } else
                    cout << "No\n";
            }
        }
    }

    return 0;
}