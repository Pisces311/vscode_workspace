#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

int n, k;

struct node {
    int x, y;
    string id;
    bool operator<(const node &p) const { return id < p.id; }
} a[maxn];

string dfs(int x, int y, int s, int d) {
    int mid = s >> 1;
    string ans;
    if (d >= 1) {
        if (x <= mid && y <= mid)
            ans = "1" + dfs(y, x, mid, d - 1);
        else if (x > mid && y <= mid)
            ans = "2" + dfs(x - mid, y, mid, d - 1);
        else if (x > mid && y > mid)
            ans = "3" + dfs(x - mid, y - mid, mid, d - 1);
        else if (x <= mid && y > mid)
            ans = "4" + dfs(mid - (y - mid) + 1, mid - x + 1, mid, d - 1);
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].id = dfs(a[i].x, a[i].y, pow(2, k), k);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) cout << a[i].x << ' ' << a[i].y << '\n';

    return 0;
}