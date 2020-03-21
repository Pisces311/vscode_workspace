#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
ll N, K;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> K;
        ll cur = 1;
        while (N >= cur) {
            N -= cur;
            cur *= K;
        }
        cout << N + cur / K - (N + K - 1) / K << '\n';
    }

    return 0;
}