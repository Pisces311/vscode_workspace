#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;

char a[maxn];
char b[maxn];
int mark[maxn], cnt = 0, dif = 0, ans = 0;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int alen = strlen(a + 1), blen = strlen(b + 1);
    up(i, 1, alen - 1) if (a[i] != a[i + 1]) mark[i] = 1;
    up(i, 1, blen) {
        if (a[i] != b[i]) ++cnt;
        if (mark[i]) ++dif;
    }
    if (cnt % 2 == 0) ++ans;
    up(i, blen + 1, alen) {
        cnt += dif;
        dif -= mark[i - blen];
        dif += mark[i];
        if (cnt & 1) continue;
        ++ans;
    }
    printf("%d\n", ans);

    return 0;
}