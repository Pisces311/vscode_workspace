#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int t, k;
ll last_ans;
priority_queue<ll, vector<ll>, greater<ll>> pq;

ll a(ll n) {
    ll res = n;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t >> k >> last_ans;
    for (int i = 1; i <= t; ++i) {
        ll x = a(i + last_ans);
        if (pq.size() < k)
            pq.push(x);
        else if (x > pq.top()) {
            pq.pop();
            pq.push(x);
        }
        if (i % 100 == 0) {
            cout << pq.top() << ' ';
            last_ans = pq.top();
        }
    }
    cout << '\n';

    return 0;
}