#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int N;
int a[maxn], dp1[maxn], dp2[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) dp1[i] = dp2[i] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j < i; ++j)
            if (a[j] < a[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
    }
    for (int i = N; i >= 1; --i) {
        for (int j = i - 1; j >= 1; --j) {
            if (a[j] > a[i]) dp2[j] = max(dp2[j], dp2[i] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) ans = max(ans, dp1[i] + dp2[i] - 1);
    cout << N - ans << '\n';

    return 0;
}