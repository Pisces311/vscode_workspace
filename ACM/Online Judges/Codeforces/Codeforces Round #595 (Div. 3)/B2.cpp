#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int q, n;
int a[maxn], ans[maxn];
vector<int> term;

void solve(int x) {
    term.clear();
    term.push_back(x);
    int cur = a[x], day = 1;
    while (cur != x) {
        term.push_back(cur);
        cur = a[cur];
        ++day;
    }
    for (int i : term) ans[i] = day;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--) {
        for (int i = 1; i <= n; ++i) ans[i] = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i)
            if (!ans[i]) solve(i);
        for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}