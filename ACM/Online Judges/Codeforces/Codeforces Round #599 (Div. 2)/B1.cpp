#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;

int k, n;
char s[maxn], t[maxn];

bool solve() {
    int p1 = -1, p2 = -1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != t[i]) {
            if (p1 == -1)
                p1 = i;
            else if (p2 == -1)
                p2 = i;
            else
                return false;
        }
    }
    if (p1 != -1 && p2 == -1) return false;
    if (s[p1] == s[p2] && t[p1] == t[p2]) return true;
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    while (k--) {
        cin >> n;
        cin >> (s + 1);
        cin >> (t + 1);
        if (solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}