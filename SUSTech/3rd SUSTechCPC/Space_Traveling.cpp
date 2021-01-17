#include <iostream>
using namespace std;

typedef long long ll;

int main() {

    int T;
    cin >> T;
    while (T--) {
        ll x, y;
        cin >> x >> y;
        int ans = 0;
        while (x != y) {
            if (x > y) swap(x, y);
            y /= 2;
            ++ans;
        }
        cout << ans << '\n';
    }

    return 0;
}