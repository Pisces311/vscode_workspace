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

const ll mod = 1LL << 32;

int t;
ll n, x;
int w[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4};
ll sum[20];

ll solve(ll x) {
    if (x < 0) return 0;
    ll pw = 1, ans = 0;
    for (int i = 1; i <= 8; i++, pw <<= 4) {
        ll a = x / (pw * 16) * sum[16];  // 这一位总共完整跑了几轮
        ll b = sum[x / pw % 16];         // 跑完a轮后还有剩余b次
        ll c =
            (x % pw + 1) *
            w[x / pw % 16];  // 当前的这一位的这一个数要多加几次,0也算一个所以+1
        ans += (a + b) * pw + c;  // a和b每次都会停留pw秒
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    sum[0] = 0;
    up(i, 1, 16) sum[i] = sum[i - 1] + w[i - 1];
    scan(t);
    while (t--) {
        scanf("%lld %llx", &n, &x);
        if ((x + n - 1) >= mod) {
            printf("%lld\n",
                   solve(mod - 1) - solve(x - 1) + solve(x + n - 1 - mod));
        } else {
            printf("%lld\n", solve(n + x - 1) - solve(x - 1));
        }
    }
    return 0;
}