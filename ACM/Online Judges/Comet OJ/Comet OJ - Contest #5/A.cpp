#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int c1 = 0, c4 = 0, c5 = 0;
char str[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%s", str + 1);
    int len = strlen(str + 1);
    up(i, 1, len) {
        if (str[i] == '1') ++c1;
        if (str[i] == '4') ++c4;
        if (str[i] == '5') ++c5;
    }
    printf("%d\n", min(c1 / 3, min(c4 / 2, c5)));

    return 0;
}