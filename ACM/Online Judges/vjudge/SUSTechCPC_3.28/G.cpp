#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int T, k;
int a[maxn];

bool check() {
    for (int i = 1; i <= k; ++i)
        if (a[i] != 1) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case " << cas << ": ";
        cin >> k;
        for (int i = 1; i <= k; ++i) cin >> a[i];
        int XOR = 0;
        for (int i = 1; i <= k; ++i) XOR ^= a[i];
        bool ret = check();
        if (ret) {
            if (k & 1)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        } else if (XOR != 0)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }

    return 0;
}