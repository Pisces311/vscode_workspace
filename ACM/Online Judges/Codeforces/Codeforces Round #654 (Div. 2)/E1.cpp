#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e3 + 5;

int n, p;
int a[maxn];
vector<int> ans;

bool check(int x) {
    int take = 0;
    while (take != n) {
        int num = upper_bound(a + 1, a + n + 1, x + take) - a - 1 - take;
        if (num % p == 0) return false;
        ++take;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= 2000; ++i)
        if (check(i)) ans.push_back(i);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';

    return 0;
}