#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, N;

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
        cin >> N;
        cout << "Case #" << ++cas << ": ";
        if (N < 7)
            cout << "Draw\n";
        else if (N & 1)
            cout << "Panda\n";
        else {
            if (N < 16)
                cout << "Draw\n";
            else
                cout << "Sheep\n";
        }
    }

    return 0;
}