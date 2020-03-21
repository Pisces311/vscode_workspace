#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, a, b;
vector<int> v;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    v.push_back(5);
    v.push_back(2);
    v.push_back(1);
    while (T--) {
        int ans = 0;
        cin >> a >> b;
        if (a > b) swap(a, b);
        for (int vol : v) {
            int ret = (b - a) / vol;
            ans += ret;
            a += ret * vol;
        }
        cout << ans << '\n';
    }

    return 0;
}