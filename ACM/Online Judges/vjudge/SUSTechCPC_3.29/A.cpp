#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e5 + 5;

int n;
int a[maxn];
int l[maxn], r[maxn];
stack<int> stk;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[n + i];
    for (int i = 1; i <= n; ++i) a[i] = a[2 * n + i] = a[n + i];
    for (int i = 1; i <= 3 * n; ++i) {
        while (!stk.empty() && a[stk.top()] > a[i]) stk.pop();
        l[i] = stk.empty() ? 0 : stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    for (int i = 3 * n; i >= 1; --i) {
        while (!stk.empty() && a[stk.top()] > a[i]) stk.pop();
        r[i] = stk.empty() ? 0 : stk.top();
        stk.push(i);
    }
    int ans = 0x3f3f3f3f;
    int id[3];
    for (int i = n + 1; i <= 2 * n; ++i)
        if (l[i] && r[i] && ans > r[i] - l[i]) {
            ans = r[i] - l[i];
            id[0] = l[i];
            id[1] = i;
            id[2] = r[i];
        }
    for (int i = 0; i < 3; ++i)
        while (id[i] > n) id[i] -= n;
    cout << id[0] << ' ' << id[1] << ' ' << id[2] << '\n';

    return 0;
}