#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

int n;
int a[maxn];
int stk[maxn], top = 0;
vector<int> v;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        bool ok = true;
        for (int j = 1; j <= top; ++j)
            if (stk[j] == a[i]) ok = false;
        if (ok)
            stk[++top] = a[i];
        else
            break;
    }
    int ans = n - top;
    for (int i = n; i >= 1; --i) {
        bool ok = true;
        for (int j : v)
            if (j == a[i]) ok = false;
        if (!ok) break;
        for (int j = 1; j <= top; ++j)
            if (stk[j] == a[i]) top = j - 1;
        v.push_back(a[i]);
        ans = min(ans, n - top - (int)v.size());
    }
    cout << ans << '\n';

    return 0;
}