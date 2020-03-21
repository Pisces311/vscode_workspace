#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

ll k, c[maxn], fa[maxn];
int ans[maxn], mx = 1;

ll dfs(ll k, int id) {
    if (k == 1) {
        return c[id] = 1;
    }
    if (k == 2) {
        c[id] = 1;
        fa[++mx] = id;
        c[mx] = 1;
        return 1;
    }
    if (k & 1) {
        k -= 1;
        if (k == 2) {
            fa[++mx] = id;
            c[id] += dfs(2, mx);
        } else {
            fa[++mx] = id;
            c[id] += dfs(k / 2, mx);
            fa[++mx] = id;
            c[id] += dfs(2, mx);
        }
    } else {
        fa[++mx] = id;
        c[id] += dfs(k - 1, mx);
    }
    return c[id];
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    if (k == 1) {
        cout << 2 << '\n';
        cout << 1 << '\n';
        cout << "1 2" << '\n';
        return 0;
    }
    dfs(k, 1);
    cout << mx << '\n';
    for (int i = 2; i <= mx; i++) {
        if (i == mx)
            cout << fa[i] << '\n';
        else
            cout << fa[i] << " ";
    }
    for (int i = 1; i <= mx; i++) {
        if (i == mx)
            cout << c[i] << '\n';
        else
            cout << c[i] << " ";
    }

    return 0;
}