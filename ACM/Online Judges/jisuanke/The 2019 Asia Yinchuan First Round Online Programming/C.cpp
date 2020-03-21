#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 55;

int T, n, m;
char s[maxn], t[maxn], tar[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    int cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        cin >> n >> m;
        cin >> (s + 1) >> (t + 1);
        cin >> (tar + 1);
        int code = t[1] - s[1];
        for (int i = 1; i <= m; ++i) {
            tar[i] -= code;
            if (tar[i] > 'Z')
                tar[i] -= 26;
            else if (tar[i] < 'A')
                tar[i] += 26;
        }
        cout << (tar + 1) << '\n';
    }

    return 0;
}