#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int maxn = 1e5 + 5;

struct node {
    int val, id;
    bool operator<(const node& a) { return val > a.val; }
} col[maxn];

int n, r;
map<pii, int> ma;
int row[maxn];

int check(int x, int y) {
    int num = 0;
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            pii p = make_pair(x + i * r, y + j * r);
            if (ma.count(p)) num += ma[p];
        }
    }
    return num;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r;
    int x, y;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        ++ma[make_pair(x, y)];
        ++row[x], ++col[y].val;
        if (x - r >= 0) ++row[x - r];
        if (x - 2 * r >= 0) ++row[x - 2 * r];
        if (y - r >= 0) ++col[y - r].val;
        if (y - 2 * r >= 0) ++col[y - 2 * r].val;
    }
    for (int i = 0; i <= 1e5; ++i) col[i].id = i;
    sort(col, col + 100001);
    int ans = 0;
    for (int i = 0; i <= 1e5; ++i) {
        for (int j = 0; j < 20; ++j) {
            ans = max(ans, row[i] + col[j].val - check(i, col[j].id));
        }
    }
    cout << ans << '\n';

    return 0;
}