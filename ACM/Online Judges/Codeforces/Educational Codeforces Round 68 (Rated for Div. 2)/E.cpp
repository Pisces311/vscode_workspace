#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 5e3 + 5;
const int N = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct hor {
    int x1, x2, y;
    bool operator<(const hor& a) const { return y < a.y; }
} h[maxn];

struct ver {
    int y1, y2, x;
    bool operator<(const ver& a) const { return y1 < a.y1; }
} v[maxn];

int n, cntv, cnth;
int c[N];

int lowbit(int x) { return x & (-x); }

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) ans += c[i];
    return ans;
}

int get_sum(int l, int r) { return sum(r) - sum(l - 1); }

void update(int x, int val) {
    for (int i = x; i <= N; i += lowbit(i)) c[i] += val;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    cntv = cnth = 0;
    for (int i = 1; i <= n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1 += 5001, y1 += 5001, x2 += 5001, y2 += 5001;
        if (x1 == x2)
            v[++cntv] = {min(y1, y2), max(y1, y2), x1};
        else
            h[++cnth] = {min(x1, x2), max(x1, x2), y1};
    }
    sort(h + 1, h + cnth + 1);
    sort(v + 1, v + cntv + 1);
    ll ans = 0;
    for (int i = 1; i <= cnth; ++i) {
        memset(c, 0, sizeof(c));
        for (int j = 1, k = 1; k < i;) {
            if (v[j].y1 <= h[k].y && j <= cntv) {
                if (v[j].x >= h[i].x1 && v[j].x <= h[i].x2 && v[j].y2 >= h[i].y)
                    update(v[j].x, 1);
                ++j;
            } else {
                int res = get_sum(h[k].x1, h[k].x2);
                ans += 1ll * res * (res - 1) / 2;
                ++k;
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}