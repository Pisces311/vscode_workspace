#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e3 + 5;

struct node {
    int v, w;
    bool operator<(const node& a) const { return w > a.w; }
};

int t, n, ans;
bool vis[maxn];
int price[maxn];
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
        up(i, 1, n) if (i != t.v && !vis[i]) pq.push({i, g[t.v][i]});
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;
        init();
        up(i, 1, n) cin >> price[i];
        up(i, 1, n) up(j, 1, n) {
            cin >> g[i][j];
            g[i][j] += price[i] + price[j];
        }
        prim();
        cout << ans << endl;
    }

    return 0;
}