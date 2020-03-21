#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e1 + 5;
const int inf = 0x3f3f3f3f;

int n;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    bool flag = true;
    while (true) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        n = sum;
        if (n == 4) {
            flag = false;
            break;
        }
        if (n == 1) break;
    }
    if (flag)
        printf("HAPPY\n");
    else
        printf("UNHAPPY\n");

    return 0;
}