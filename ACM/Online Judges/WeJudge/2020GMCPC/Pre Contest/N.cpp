#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 200;

struct grid {
    int x, y, id, num;
    bool operator<(const grid& a) const { return id < a.id; }
} a[maxn * maxn];

int n;
bitset<25> xbit, ybit, ans;
pair<int, int> res;

int cal(int x, int y) {
    xbit = x, ybit = y;
    for (int i = 0; i < 25; ++i) {
        if (i & 1)
            ans[i] = xbit[i / 2];
        else
            ans[i] = ybit[i / 2];
    }
    return (int)ans.to_ulong();
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n * n; ++i) {
        cin >> a[i].num;
        a[i].x = i / n;
        a[i].y = i % n;
        a[i].id = cal(a[i].x, a[i].y);
    }
    sort(a, a + n * n);
    res = make_pair(a[0].num, 1);
    for (int i = 1; i < n * n; ++i) {
        if (a[i].num == res.first)
            ++res.second;
        else {
            cout << res.first << ',' << res.second << ' ';
            res = make_pair(a[i].num, 1);
        }
    }
    cout << res.first << ',' << res.second << '\n';

    return 0;
}