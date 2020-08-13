#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct point {
    ll x, y;
} p[4];

struct vct {
    point start, end;
};

ll cross_product(vct a, vct b) {
    return (a.end.x - a.start.x) * (b.end.y - b.start.y) -
           (b.end.x - b.start.x) * (a.end.y - a.start.y);
}

int T;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        for (int i = 1; i <= 3; ++i) cin >> p[i].x >> p[i].y;
        vct vct1 = {p[1], p[2]}, vct2 = {p[2], p[3]};
        ll ret = cross_product(vct1, vct2);
        if (ret < 0)
            cout << "Clockwise\n";
        else
            cout << "Counterclockwise\n";
    }

    return 0;
}