#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

ll x, y, a, b;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%lld %lld %lld %lld", &x, &a, &y, &b)) {
        int res = (x / a) - (y / b);
        if (res > 0)
            puts(">");
        else if (res < 0)
            puts("<");
        else {
            x = x % a;
            y = y % b;
            ll ans = x * b - y * a;
            if (ans > 0)
                puts(">");
            else if (ans < 0)
                puts("<");
            else
                puts("=");
        }
    }

    return 0;
}