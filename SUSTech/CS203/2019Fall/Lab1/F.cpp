#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n;
vector<int> divi;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        n *= 2;
        divi.clear();
        int ans = -1;
        for (int i = 2; i <= sqrt(n); ++i)
            if (n % i == 0) divi.push_back(i);
        for (int i : divi) {
            if ((n / i + 1 - i) % 2 == 0) {
                ans = i;
                break;
            }
        }
        if (ans != -1)
            cout << ans << '\n';
        else
            cout << "impossible\n";
    }

    return 0;
}