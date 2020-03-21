#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

struct point {
    ll x, y;
} p[maxn];

int i;
ll x0, y0, ax, ay, bx, by, xs, ys, t;

int get_right(int j) {
    ll tt = t;
    int cnt = 0;
    point s = {xs, ys};
    for (int k = j; k < i; ++k) {
        ll dis = abs(p[k].x - s.x) + abs(p[k].y - s.y);
        if (tt >= dis) {
            ++cnt;
            tt -= dis;
            s = p[k];
        } else
            break;
    }
    return cnt;
}

int get_left(int j) {
    ll tt = t;
    int cnt = 0;
    point s = {xs, ys};
    for (int k = j; k >= 0; --k) {
        ll dis = abs(p[k].x - s.x) + abs(p[k].y - s.y);
        if (tt >= dis) {
            ++cnt;
            tt -= dis;
            s = p[k];
        } else
            break;
    }
    return cnt;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    p[0] = {x0, y0};
    for (i = 1; i <= 100; ++i) {
        ll x = ax * p[i - 1].x + bx;
        ll y = ay * p[i - 1].y + by;
        if (x > 2e16 || y > 2e16) break;
        p[i] = {x, y};
    }
    int ans = 0;
    for (int j = 0; j < i; ++j) {
        int cur = max(get_right(j), get_left(j));
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}