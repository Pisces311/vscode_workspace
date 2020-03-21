#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int def, sta;
    bool operator<(const node& a) const {
        return sta == a.sta ? def < a.def : sta < a.sta;
    }
} b[maxn];

int T, n, m;
int a[maxn], sta[maxn];
bool vis[maxn];

ll strategy1() {
    ll ans = 0;
    memset(vis, false, sizeof(vis));
    for (int i = m, j = 1; i >= 1; --i) {
        if (b[i].sta == 1) {
            int pos = upper_bound(a + 1, a + n + 1, b[i].def) - a;
            if (pos == n + 1) return 0;
            vis[pos] = true;
        } else {
            while (j <= n && a[j] < b[i].def && !vis[j]) ++j;
            ans += a[j] - b[i].def;
            vis[j] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) ans += a[i];
    return ans;
}

ll strategy2() {
    ll ans = 0;
    for (int i = n, j = 1; i >= 1 && j <= m; --i, ++j) {
        if (b[j].sta == 0) ans += max(0, a[i] - b[j].def);
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    for (int kas = 1; kas <= T; ++kas) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= m; ++i) scanf("%d", &b[i].def);
        for (int i = 1; i <= m; ++i) scanf("%d", &b[i].sta);
        sort(b + 1, b + m + 1);
        printf("Case %d: %lld\n", kas, max(strategy1(), strategy2()));
    }

    return 0;
}