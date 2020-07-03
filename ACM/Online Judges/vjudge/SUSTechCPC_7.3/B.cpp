#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e2 + 5;

struct point {
    int x, y;
} a[maxn];

int N;
bool vis[maxn][maxn];

bool check(point p) {
    return -100 <= p.x && p.x <= 100 && -100 <= p.y && p.y <= 100 &&
           vis[p.x + 100][p.y + 100];
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N) {
        for (int i = 1; i <= N; ++i) cin >> a[i].x >> a[i].y;
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= N; ++i) vis[a[i].x + 100][a[i].y + 100] = true;
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                int dx = a[j].x - a[i].x, dy = a[j].y - a[i].y;
                point p3 = {a[i].x + dy, a[i].y - dx};
                if (check(p3)) {
                    point p4 = {p3.x + dx, p3.y + dy};
                    if (check(p4)) ++ans;
                }
                p3 = {a[i].x - dy, a[i].y + dx};
                if (check(p3)) {
                    point p4 = {p3.x + dx, p3.y + dy};
                    if (check(p4)) ++ans;
                }
            }
        }
        cout << ans / 4 << '\n';
    }

    return 0;
}