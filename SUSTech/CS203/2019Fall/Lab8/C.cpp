#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

int T, N;
priority_queue<ll, vector<ll>, greater<ll> > pq;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            int val;
            cin >> val;
            pq.push(val);
        }
        ll ans = 0;
        while (true) {
            ll a = pq.top();
            pq.pop();
            if (pq.size()) {
                ll b = pq.top();
                pq.pop();
                ans += a + b;
                pq.push(a + b);
            } else
                break;
        }
        cout << ans << '\n';
    }

    return 0;
}