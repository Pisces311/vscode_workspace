#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e3 + 5;

ll n, h, ans;
ll bot[maxn], tmp[maxn];

bool judge(int m) {
    up(i, 1, m) tmp[i] = bot[i];
    sort(tmp + 1, tmp + m + 1);
    ll left = h;
    ll cnt = m;
    while (cnt >= 1) {
        left -= tmp[cnt];
        cnt -= 2;
    }
    if (left >= 0) return true;
    return false;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scanf("%lld %lld", &n, &h);
    up(i, 1, n) scan(bot[i]);
    ll l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (judge(mid)){
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    print(ans);

    return 0;
}