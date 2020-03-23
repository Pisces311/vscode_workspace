#include <iostream>
#include <string.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T;
char s[1005];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> s;
        int len = strlen(s);
        cout << (1 + len) * len / 2 << '\n';
    }

    return 0;
}