#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int T, n, k;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        if (k % 3) {
            if (n % 3)
                printf("Alice\n");
            else
                printf("Bob\n");
        } else {
            n %= (k + 1);
            if (n == k || n % 3)
                printf("Alice\n");
            else
                printf("Bob\n");
        }
    }

    return 0;
}