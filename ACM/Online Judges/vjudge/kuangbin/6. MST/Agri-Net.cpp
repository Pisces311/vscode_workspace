#include <string.h>
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

const int maxn = 1e2 + 5;

struct node {
    int v, w;
    bool operator<(const node& a) const { return w > a.w; }
};

int N, ans;
bool vis[maxn];
int g[maxn][maxn];
priority_queue<node> pq;

inline void init() {
    ans = 0;
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
        up(i, 1, N) if (!vis[i] && i != t.v) pq.push({i, g[t.v][i]});
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    while (cin >> N) {
        init();
        up(i, 1, N) up(j, 1, N) cin >> g[i][j];
        prim();
        cout << ans << endl;
    }

    return 0;
}