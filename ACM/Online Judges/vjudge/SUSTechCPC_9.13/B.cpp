#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, N, K;
ll M;
int a[maxn];

bool check(int mid) {
    ll cnt = 0, tot = 0;
    int l = 1, r = K;
    for (int i = 1; i <= K; ++i)
        if (a[i] > mid) ++cnt;
    while (r <= N) {
        while (r <= N && cnt < K) {
            ++r;
            if (a[r] > mid) ++cnt;
        }
        tot += N - r + 1;
        if (a[l] > mid) --cnt;
        ++l;
    }
    return tot < M;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N >> K >> M;
        for (int i = 1; i <= N; ++i) cin >> a[i];
        int l = 1, r = 1e9, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}