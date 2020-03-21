#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int n, cnt1 = 0, cnt0 = 0;
char a[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    scanf("%s", a + 1);
    up(i, 1, n) {
        if (a[i] == '0')
            ++cnt0;
        else
            ++cnt1;
    }
    if (cnt1 != cnt0)
        printf("1\n%s\n", a + 1);
    else {
        printf("2\n%c ", a[1]);
        up(i, 2, n) printf("%c", a[i]);
        printf("\n");
    }

    return 0;
}