#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    ll R, C;
    cin >> R >> C;
    ll cnt = 0;
    if (N <= K) {
        for (int i = 1; i <= N; i++) {
            cout << "T " << i << endl;
            cin >> R >> C;
            cnt += C;
        }
        cout << "E " << cnt / 2 << endl;
    } else {
        srand((unsigned)time(0));
        ll slot = N / K;
        for (ll i = 1; i <= K; i++) {
            ll l = (i - 1) * slot + 1, r = i * slot;
            ll mid = (rand() % (r - l + 1)) + l;
            cout << "T " << mid << endl;
            cin >> R >> C;
            cnt += C;
        }
        ll est = cnt / (K / (1.0 * N));
        cout << "E " << est / 2 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}