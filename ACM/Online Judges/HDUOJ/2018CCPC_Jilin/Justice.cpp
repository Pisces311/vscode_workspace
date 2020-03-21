#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int w, id;
    bool operator<(const node& a) const { return w < a.w; }
} a[maxn];

int T, n;
bool take[maxn];

bool solve() {
    int g1 = 1, g2 = 1, need = 1;
    for (int i = 1; i <= n; ++i) {
        while (g1 + g2 <= n - i + 1 && need < a[i].w) {
            g1 <<= 1;
            g2 <<= 1;
            ++need;
        }
        if (g1 + g2 > n - i + 1) return false;
        if (g1) {
            g1--;
            take[a[i].id] = 1;
        } else
            g2--;
        if (!g1 && !g2) break;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    for (int kas = 1; kas <= T; ++kas) {
        scanf("%d", &n);
        memset(take, false, sizeof(take));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].w);
            a[i].id = i;
        }
        sort(a + 1, a + n + 1);
        printf("Case %d: ", kas);
        if (!solve()) {
            puts("NO");
            continue;
        } else
            puts("YES");
        for (int i = 1; i <= n; ++i) printf(take[i] ? "1" : "0");
        printf("\n");
    }

    return 0;
}