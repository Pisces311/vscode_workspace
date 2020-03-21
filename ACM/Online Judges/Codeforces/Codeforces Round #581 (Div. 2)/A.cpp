#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

char s[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> (s + 1);
    int len = strlen(s + 1);
    bool exact = true;
    for (int i = 2; i <= len; ++i)
        if (s[i] == '1') exact = false;
    int cnt = 0;
    for (int i = len; i >= 1; i -= 2) {
        if (i == 1 && exact) continue;
        ++cnt;
    }
    cout << cnt << '\n';

    return 0;
}