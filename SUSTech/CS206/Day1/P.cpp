#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int t;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &t)) {
        if (t < 0 || t > 100)
            printf("Score is error!\n");
        else if (t >= 90)
            printf("A\n");
        else if (t >= 80)
            printf("B\n");
        else if (t >= 70)
            printf("C\n");
        else if (t >= 60)
            printf("D\n");
        else
            printf("E\n");
    }

    return 0;
}