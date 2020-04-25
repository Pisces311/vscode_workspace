#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct student {
    int m, r;
    bool operator<(const student& a) const { return r > a.r; }
} a[maxn];

int n;
int assign[maxn], finish[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].m >> a[i].r;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) assign[i] = assign[i - 1] + a[i].m;
    int Max = 0;
    for (int i = 1; i <= n; ++i) Max = max(Max, assign[i] + a[i].r);
    cout << "Project " << n << ": " << Max << '\n';

    return 0;
}