#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, m;
char s1[maxn], s2[maxn];

bool is_equal() {
    for (int i = 1; i <= n; ++i)
        if (s1[i] != s2[i]) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> (s1 + 1) >> (s2 + 1);
    n = strlen(s1 + 1);
    m = strlen(s2 + 1);
    if (n < m) {
        swap(n, m);
        swap(s1, s2);
    }
    if (n != m) {
        cout << n << '\n';
    } else {
        if (is_equal()) {
            cout << "-1\n";
        } else {
            cout << n << '\n';
        }
    }

    return 0;
}