#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e2 + 5;

struct node {
    double x, y, z, r;
} N[maxn];

struct edge {
    int v;
    double w;
    bool operator<(const edge& a) const { return w > a.w; }
};

int n;
double ans;
bool vis[maxn];
priority_queue<edge> pq;

inline void init() {
    mem(vis, false);
    ans = 0;
}

double get_dis(const node& a, const node& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

void prim() {
    pq.push({1, 0});
    while (!pq.empty()) {
        edge t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        ans += t.w;
        up(i, 1, n) if (t.v != i && !vis[i])
            pq.push({i, max(0.0, get_dis(N[t.v], N[i]) - N[t.v].r - N[i].r)});
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    while (scan(n)) {
        if (n == 0) break;
        init();
        up(i, 1, n)
            scanf("%lf %lf %lf %lf", &N[i].x, &N[i].y, &N[i].z, &N[i].r);
        prim();
        printf("%.3f\n", ans);
    }

    return 0;
}