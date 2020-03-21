#include <stdio.h>
#include <utility>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

int T, n;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(T);
    up(i, 1, T){
        scan(n);
        ll ans = 1ll * (1 + n) * n / 2 - 1;
        printf("Case #%d: %lld\n", i, ans);
    }

    return 0;
}