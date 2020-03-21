#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int T;
char s[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> (s + 1);
        int len = strlen(s + 1);
        for (int i = 1; i <= len; ++i) {
            if (s[i] == 'y')
                continue;
            else if (s[i] == 'z') {
                s[i] = 'b';
                break;
            } else
                break;
        }
        cout << (s + 1) << '\n';
    }

    return 0;
}