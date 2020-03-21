#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    ll x, y;
} Eve, Neko;

ll N, x[maxn], y[maxn];
char s[maxn];

bool check(ll mid) {
    ll round = mid / N, exc = mid % N;
    ll dx = x[N] * round, dy = y[N] * round;
    dx += x[exc];
    dy += y[exc];
    if (abs(Neko.x - dx) + abs(Neko.y - dy) <= mid) return true;
    return false;
}

ll binary_search() {
    ll l = 1, r = 1ll << 60, ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> Eve.x >> Eve.y >> Neko.x >> Neko.y >> N;
    Neko.x -= Eve.x;
    Neko.y -= Eve.y;
    cin >> (s + 1);
    for (int i = 1; i <= N; ++i) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
        if (s[i] == 'L') x[i]++;
        if (s[i] == 'R') x[i]--;
        if (s[i] == 'U') y[i]--;
        if (s[i] == 'D') y[i]++;
    }
    cout << binary_search() << '\n';

    return 0;
}