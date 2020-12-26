#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

ll N, I, M, K;
ll a[maxn], tmp[maxn];
bool morning = false;

bool check(ll mid) {
    ll cur = N + mid * I, sum = 0;
    for (int i = 1; i <= M; ++i) {
        if (mid * K < a[i])
            tmp[i] = a[i] - mid * K;
        else {
            if (K == 0)
                tmp[i] = a[i];
            else
                tmp[i] = (a[i] % K == 0) ? K : a[i] % K;
        }
        sum += tmp[i];
    }
    if (cur >= sum) {
        if (cur - I >= sum)
            morning = true;
        else
            morning = false;
        return true;
    } else
        return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> I >> M >> K;
    for (int i = 1; i <= M; ++i) {
        cin >> a[i];
        a[i] += K;
    }
    ll l = 1, r = 1e11, ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else
            l = mid + 1;
    }
    cout << ans << ' ' << (morning ? "morning" : "evening") << '\n';

    return 0;
}