#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

struct point {
    int x, y;
    bool operator<(const point& a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
} p[maxn];

int n;
map<point, int> ma;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            point c = {p[i].x + p[j].x, p[i].y + p[j].y};
            ++ma[c];
        }
    int cnt = 0;
    for (auto i : ma) cnt = max(cnt, i.second);
    cout << n - cnt << '\n';

    return 0;
}