#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int n;
int d[maxn], s[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    int Max = *max_element(d + 1, d + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = ceil(50.0 * d[i] / Max);
    for (int i = 1; i <= n; ++i) {
        cout << '+';
        for (int j = 1; j <= s[i]; ++j) cout << '-';
        cout << "+\n|";
        for (int j = 1; j < s[i]; ++j) cout << ' ';
        if (d[i] != 0)
            cout << (d[i] == Max ? "*|" : " |");
        else
            cout << '|';
        cout << d[i] << '\n';
        cout << '+';
        for (int j = 1; j <= s[i]; ++j) cout << '-';
        cout << "+\n";
    }

    return 0;
}