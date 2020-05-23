#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 4e5 + 5;

int N;
char s[maxn];

bool ok(int i) {
    for (int j = i, k = N; j <= N; ++j, --k) {
        if (s[j] != s[k]) return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> (s + 1);
    for (int i = 1; i <= N; ++i)
        if (ok(i)) {
            cout << i - 1 << '\n';
            break;
        }

    return 0;
}