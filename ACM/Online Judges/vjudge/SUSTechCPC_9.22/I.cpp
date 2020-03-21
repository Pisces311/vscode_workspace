#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

char T[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> (T + 1);
    int pos = 0, len = strlen(T + 1);
    for (int i = 1; i <= len; ++i)
        if (T[i] >= '0' && T[i] <= '9')
            pos = i;
        else
            break;
    if (pos == 0)
        cout << "-1\n";
    else {
        for (int i = 1; i <= pos; ++i) cout << T[i];
        cout << '\n';
    }

    return 0;
}