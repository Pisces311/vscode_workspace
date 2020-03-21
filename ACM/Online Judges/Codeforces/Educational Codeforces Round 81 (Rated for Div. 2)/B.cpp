#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n, x, Max, Min, cnt;
map<int, int> m;
char s[maxn];

int solve() {
    int val = 0;
    if (x == 0) ++val;
    if (cnt > 0) {
        int dif = x - Max, ans = 0;
        if (dif > 0) {
            dif = dif / cnt * cnt;
            x -= dif;
        }
        while (x >= Min) {
            ans += m[x];
            x -= cnt;
        }
        return ans + val;
    } else if (cnt == 0) {
        if (x >= Min && x <= Max)
            return -1;
        else
            return val;
    } else {
        int dif = Min - x, ans = 0;
        if (dif > 0) {
            dif = dif / cnt * cnt;
            x += dif;
        }
        while (x <= Max) {
            ans += m[x];
            x -= cnt;
        }
        return ans + val;
    }
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
        m.clear();
        cin >> n >> x;
        cin >> (s + 1);
        Max = INT_MIN, Min = INT_MAX, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '0')
                ++cnt;
            else
                --cnt;
            Max = max(Max, cnt);
            Min = min(Min, cnt);
            ++m[cnt];
        }
        cout << solve() << '\n';
    }

    return 0;
}