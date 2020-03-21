#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
int a[10], d[40][3], ans;

void init() {
    int cnt = 0;
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j + i <= 9; ++j) {
            d[cnt][0] = i;
            d[cnt][1] = j;
            d[cnt++][2] = i + j;
        }
}

bool check(int x) {
    if (a[d[x][0]] < 0 || a[d[x][1]] < 0 || a[d[x][2]] < 0) return false;
    return true;
}

void add(int x, int val) {
    a[d[x][0]] += val;
    a[d[x][1]] += val;
    a[d[x][2]] += val;
}

void dfs(int deep, int cnt) {
    if (36 - deep + cnt <= ans || deep == 36) return;
    add(deep, -1);
    if (check(deep)) {
        ans = max(ans, cnt + 1);
        dfs(deep + 1, cnt + 1);
    }
    add(deep, 1);
    dfs(deep + 1, cnt);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> T;
    int cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        for (int i = 1; i <= 9; ++i) {
            cin >> a[i];
            a[i] = min(a[i], 17 - i);
        }
        ans = 0;
        dfs(0, 0);
        cout << ans << '\n';
    }

    return 0;
}