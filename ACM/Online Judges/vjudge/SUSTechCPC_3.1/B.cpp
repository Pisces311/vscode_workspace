#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int a[5];
int w, h;

bool check() {
    int p = 2 * (a[1] + a[2]), q = a[3] + 2 * a[1];
    if ((p <= w && q <= h) || (p <= h && q <= w))
        return true;
    else {
        p = a[1] + a[3] + 3 * a[2], q = a[1] + a[3];
        if ((p <= w && q <= h) || (p <= h && q <= w)) return true;
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a[1] >> a[2] >> a[3];
    cin >> w >> h;
    sort(a + 1, a + 4);
    do {
        if (check()) {
            cout << "Yes\n";
            return 0;
        }
    } while (next_permutation(a + 1, a + 4));
    cout << "No\n";

    return 0;
}