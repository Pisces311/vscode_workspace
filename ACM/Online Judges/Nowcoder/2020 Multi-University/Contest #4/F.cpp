#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, AC, AD, BC, BD;

bool C_is_left() {
    if (AC <= BC) {
        if (AD > BD)
            return true;
        else
            return BC > BD;
    } else {
        if (AD <= BD)
            return false;
        else
            return AD > AC;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> AC >> AD >> BC >> BD;
        if (C_is_left())
            cout << "AB//CD\n";
        else
            cout << "AB//DC\n";
    }

    return 0;
}