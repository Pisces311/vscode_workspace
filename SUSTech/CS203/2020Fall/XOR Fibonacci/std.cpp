#include <iostream>
using namespace std;

int T, a, b, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> a >> b >> n;
        int ans[] = {a, b, a ^ b};
        cout << ans[n % 3] << '\n';
    }

    return 0;
}