#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 5e2 + 5;

struct coor {
    int x, y;
    double operator-(const coor& a) {
        return sqrt(1.0 * pow(x - a.x, 2) + pow(y - a.y, 2));
    }
} p[maxn];

struct node {
    int v;
    double w;
    bool operator<(const node& a) const { return w > a.w; }
};

int N, S, P, top;
double ans[maxn];
double g[maxn][maxn];
bool vis[maxn];
priority_queue<node> pq;

inline void init() {
    top = -1;
    mem(vis, false);
}

void prim() {
    pq.push({1, 0});
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        ans[++top] = t.w;
        up(i, 1, P) if (!vis[i] && i != t.v) pq.push({i, g[t.v][i]});
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> N;
    while (N--) {
        cin >> S >> P;
        init();
        up(i, 1, P) cin >> p[i].x >> p[i].y;
        up(i, 1, P) up(j, i + 1, P) g[i][j] = g[j][i] = p[i] - p[j];
        prim();
        sort(ans + 1, ans + top + 1);
        cout.flags(ios::fixed);
        cout.precision(2);
        cout << ans[P - S] << endl;
    }

    return 0;
}