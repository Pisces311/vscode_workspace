#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

string s;
ll a, b, c, d, e, n, val;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    a = b = c = d = e = 0;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        switch (s[i]) {
            case 'w':
                a += val;
                break;
            case 'r':
                b = min(a, b + val);
                break;
            case 'o':
                c = min(b, c + val);
                break;
            case 'n':
                d = min(c, d + val);
                break;
            case 'g':
                e = min(d, e + val);
                break;
        }
    }
    cout << e << '\n';

    return 0;
}