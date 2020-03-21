#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
int A1, A2, A3, A4;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> A1 >> A2 >> A3 >> A4;
        int cnt = 0;
        if (A1) ++cnt;
        if (A2) ++cnt;
        if (A3) ++cnt;
        if (A4) ++cnt;
        if (!cnt) cout << "Typically Otaku\n";
        if (cnt == 1) cout << "Eye-opener\n";
        if (cnt == 2) cout << "Young Traveller\n";
        if (cnt == 3) cout << "Excellent Traveller\n";
        if (cnt == 4) cout << "Contemporary Xu Xiake\n";
    }

    return 0;
}