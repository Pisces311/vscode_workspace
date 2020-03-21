#include <stdio.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n;

int eular(int n) {
    int ret = 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            n /= i, ret *= i - 1;
            while (n % i == 0) n /= i, ret *= i;
        }
    if (n > 1) ret *= n - 1;
    return ret;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &n)) {
        if (n == 0) break;
        printf("%d\n", eular(n));
    }

    return 0;
}