#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
ll n, m;
ll a[maxn];
int num[40];
bitset<65> bit;

int fun(int x) {
    int cnt = 0;
    while (x != 1) {
        x >>= 1;
        ++cnt;
    }
    return cnt;
}

int solve() {
    int ans = 0;
    for (int i = 0; i <= 62; ++i) {
        if (bit[i]) {
            if (num[i]) {
                --num[i];
            } else {
                for (int j = i + 1; j <= 64; ++j) {
                    if (num[j]) {
                        for (int k = j; k > i; --k) {
                            num[k] -= 1;
                            num[k - 1] += 2;
                            ++ans;
                        }
                        num[i] -= 1;
                        break;
                    }
                }
            }
        }
        num[i + 1] += num[i] / 2;
        num[i] %= 2;
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

    cin >> T;
    while (T--) {
        memset(num, 0, sizeof(num));
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) cin >> a[i];
        ll sum = accumulate(a + 1, a + m + 1, 0ll);
        if (sum < n)
            cout << "-1\n";
        else {
            for (int i = 1; i <= m; ++i) ++num[fun(a[i])];
            ll dif = sum - n;
            bit = dif;
            cout << solve() << '\n';
        }
    }

    return 0;
}