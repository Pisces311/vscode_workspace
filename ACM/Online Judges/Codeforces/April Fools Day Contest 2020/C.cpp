#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
bitset<10> bit;

void swap_bit(int l, int r) {
    int tmp = bit[l];
    bit[l] = bit[r];
    bit[r] = tmp;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    bit = n;
    swap_bit(0, 4);
    swap_bit(2, 3);
    cout << bit.to_ullong() << '\n';

    return 0;
}