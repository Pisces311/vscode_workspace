#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
const int mod = 1e6 + 3;

ll a[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    a[1] = 1;
    for (int i = 2; i <= 1e6 + 3; ++i) a[i] = a[i - 1] * i % mod;
    int n;
    while (cin >> n) {
        if (n >= 1000000 + 3)
            cout << 0 << endl;
        else
            cout << a[n] << endl;
    }

    return 0;
}