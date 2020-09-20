#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t;
int num[30];
char s[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    int cas = 0;
    while (t--) {
        cout << "Case #" << ++cas << ": ";
        cin >> (s + 1);
        int n = strlen(s + 1);
        fill(num + 1, num + 27, 0);
        for (int i = 1; i <= n; ++i) ++num[s[i] - 'a' + 1];
        cout << *max_element(num + 1, num + 27) << '\n';
    }

    return 0;
}