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

const int maxn = 1e5 + 5;

int n, q;
ll le, ri;
ll str[maxn], store[maxn], pre[maxn];
ll ans = 0;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(n);
    up(i, 1, n) scanf("%lld", &str[i]);
    sort(str + 1, str + n + 1);
    up(i, 1, n - 1) store[i] = str[i + 1] - str[i];
    sort(store + 1, store + n);
    up(i, 1, n - 1) pre[i] = pre[i - 1] + store[i];
    scan(q);
    up(i, 1, q) {
        scanf("%lld %lld", &le, &ri);
        ll dif = ri - le + 1;
        int l = 1, r = n - 1;
        int mid = (l + r) / 2;
        while (l <= r) {
            if (store[mid] >= dif)
                r = mid - 1;
            else
                l = mid + 1;
            mid = (l + r) / 2;
        }
        ans = n * dif - (mid * dif - pre[mid]);
        printf("%lld ", ans);
    }
    printf("\n");

    return 0;
}