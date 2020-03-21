#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int q, n, x, y, top;
ll ans, num;
bool vis[maxn];
priority_queue<int> pq;

struct gift {
    int num, dislike;
    bool operator<(const gift& a) const {
        return num == a.num ? dislike > a.dislike : num > a.num;
    }
} g[maxn], dc[maxn];

inline void init() {
    top = 0;
    ans = num = 0;
    up(i, 1, n) g[i] = {0, 0};
    while (!pq.empty()) pq.pop();
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
            scanf("%d %d", &x, &y);
            ++g[x].num;
            if (y) ++g[x].dislike;
        }
        up(i, 1, n) if (g[i].num) dc[++top] = g[i];
        sort(dc + 1, dc + top + 1);
        int last = dc[1].num, pos = 1;
        ans += dc[1].num;
        num += dc[1].dislike;
        dc[top + 1].num = -1;
        while (pos <= top) {
            while (dc[pos + 1].num >= last - 1) pq.push(dc[++pos].dislike);
            if (pq.empty()) {
                if (++pos > top) break;
                pq.push(dc[pos].dislike);
                last = dc[pos].num + 1;
                while (dc[pos + 1].num >= last - 1) pq.push(dc[++pos].dislike);
            }
            int t = pq.top();
            pq.pop();
            ans += last - 1;
            num += min(last - 1, t);
            --last;
            if (last == 0) break;
        }
        while (!pq.empty() && last) {
            int t = pq.top();
            ans += last - 1;
            num += min(last - 1, t);
            --last;
        }
        printf("%lld %lld\n", ans, num);
    }

    return 0;
}