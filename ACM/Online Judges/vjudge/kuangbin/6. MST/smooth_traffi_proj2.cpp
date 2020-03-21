#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxc = 1e2 + 5;

struct coor {
    int x, y;
    double operator-(const coor& a) const {
        return sqrt(1.0 * pow(x - a.x, 2) + pow(y - a.y, 2));
    }
} g[maxc];

struct node {
    int v;
    double w;
    bool operator<(const node& a) const { return w > a.w; }
};

int T, C, cnt;
double ans;
bool vis[maxc];
priority_queue<node> pq;

inline void init() {
    ans = cnt = 0;
    mem(vis, false);
}

void prim() {
    pq.push({1, 0});
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        ans += t.w;
        ++cnt;
        up(i, 1, C) if (!vis[i] && i != t.v) {
            double d = g[i] - g[t.v];
            if (d < 10 || d > 1000) continue;
            pq.push({i, d});
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &C);
        init();
        up(i, 1, C) scanf("%d %d", &g[i].x, &g[i].y);
        prim();
        if (cnt == C)
            printf("%.1f\n", ans * 100);
        else
            printf("oh!\n");
    }

    return 0;
}