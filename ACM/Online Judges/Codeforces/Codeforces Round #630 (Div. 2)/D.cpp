#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int k;
int m[5][5];
bitset<30> bit;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;
    bit = k;
    cout << "2 3\n";
    m[1][2] = m[2][3] = k;
    int high = 0;
    for (int i = 29; i >= 0; --i) {
        if (bit[i]) {
            high = i + 1;
            break;
        }
    }
    bit[high] = 1;
    m[1][1] = m[2][2] = bit.to_ullong();
    for (int i = high - 1; i >= 0; --i) bit[i] = 0;
    m[2][1] = bit.to_ullong();
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= 3; ++j) cout << m[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}