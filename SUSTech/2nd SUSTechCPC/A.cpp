#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e1 + 5;

int T, n;
char s[maxn];

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
        cin >> (s + 1);
        sort(s + 1, s + n + 1);
        do {
            cout << (s + 1) << '\n';
        } while (next_permutation(s + 1, s + n + 1));
    }

    return 0;
}