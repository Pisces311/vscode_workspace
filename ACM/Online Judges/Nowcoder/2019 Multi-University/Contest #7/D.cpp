#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

int n, p;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p;
    int len = 0, tmp = p;
    while (tmp) {
        ++len;
        tmp /= 10;
    }
    if (len > n)
        cout << "T_T" << '\n';
    else {
        cout << p;
        for (int i = 1; i <= n - len; ++i) cout << 0;
        cout << '\n';
    }

    return 0;
}