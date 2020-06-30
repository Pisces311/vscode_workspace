#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int t;
char s[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> (s + 1);
        int n = strlen(s + 1), cnt0 = 0;
        for (int i = 1; i <= n; ++i)
            if (s[i] == '0') ++cnt0;
        int cnt1 = n - cnt0;
        if (min(cnt0, cnt1) & 1)
            cout << "DA\n";
        else
            cout << "NET\n";
    }

    return 0;
}