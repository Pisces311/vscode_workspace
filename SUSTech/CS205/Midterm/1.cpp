#include <iostream>
using namespace std;

typedef long long ll;

ll n;

ll cnt() {
    ll ans = 0;
    while (n) {
        ans += n / 5;
        n /= 5;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cout << cnt() << '\n';

    return 0;
}