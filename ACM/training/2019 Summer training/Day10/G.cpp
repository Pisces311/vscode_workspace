#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e6 + 5;
const int inf = 0x3f3f3f3f;

int n, x, y;
char s[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d", &n, &x, &y);
    scanf("%s", s + 1);
    bool flag = false;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '0' && !flag) {
            ++cnt;
            flag = true;
        }
        if (s[i] == '1') flag = false;
    }
    if (cnt == 0) {
        printf("0\n");
        return 0;
    }
    ll ansx = 1ll * x * (cnt - 1) + y, ansy = 1ll * y * cnt;
    if (ansx <= ansy)
        printf("%lld\n", ansx);
    else
        printf("%lld\n", ansy);

    return 0;
}