#include <iostream>
using namespace std;

const int maxn = 1e5 + 5;

int T, n;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int XOR = 0, ans = 0;
        for (int i = 1; i <= n; ++i) XOR ^= a[i];
        if (XOR) {
            for (int i = 1; i <= n; ++i) {
                if (a[i] >= (XOR ^ a[i])) ++ans;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}