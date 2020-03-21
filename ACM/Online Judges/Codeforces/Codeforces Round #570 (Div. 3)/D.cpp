#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int q, n, type, top;
int dc[maxn], w[maxn];
ll ans;

inline void init() {
    ans = 0;
    top = 0;
    up(i, 1, n) dc[i] = 0;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        init();
        up(i, 1, n) {
            scanf("%d", &type);
            ++dc[type];
        }
        up(i, 1, n) if (dc[i]) w[++top] = dc[i];
        sort(w + 1, w + top + 1);
        int last = w[top];
        ans += w[top];
        dn(i, top - 1, 1) {
            if (w[i] < last) {
                last = w[i];
                ans += w[i];
            } else {
                last = max(last - 1, 0);
                ans += last;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}