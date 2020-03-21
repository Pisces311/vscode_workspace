#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
ll A, B, N;
ll l[maxn], pre[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    int cas = 0;
    while (T--) {
        cin >> A >> B >> N;
        for (int i = 1; i <= A; ++i) cin >> l[i];
        for (int i = 1; i <= A; ++i) pre[i] = pre[i - 1] + l[i];
        while (N--) {
            ll p = lower_bound(pre + 1, pre + A + 1, A) - pre - 1;
            B = A - pre[p];
            A = p + 1;
            if (A == 1 && B == 1) break;
        }
        cout << "Case #" << ++cas << ": ";
        cout << A << '-' << B << '\n';
    }

    return 0;
}