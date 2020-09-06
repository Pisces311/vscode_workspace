#include <iostream>
using namespace std;

const int maxn = 1e2 + 5;

int T, n;
int a[maxn];

bool solve(int i) {
    int XOR = 0;
    for (int j = 1; j <= n; ++j) {
        if (j != i) {
            XOR ^= a[j];
        }
    }
    return a[i] > XOR;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (solve(i)) ++ans;
        }
        cout << ans << '\n';
    }

    return 0;
}