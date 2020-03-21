#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 2147483231;

ll T, send;
ll s0[5], num[5];

int cal(ll i) {
    int step = 0;
    while (i != send) {
        ++step;
        i = i * i % mod;
    }
    return step;
}

bool equal() {
    if (s0[1] == s0[2] && s0[2] == s0[3])
        return true;
    else
        return false;
}

void push() {
    for (int i = 1; i <= 3; ++i) s0[i] = s0[i] * s0[i] % mod;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        for (int i = 1; i <= 3; ++i) cin >> s0[i];
        cin >> send;
        for (int i = 1; i <= 3; ++i) num[i] = cal(s0[i]);
        ll mi = *min_element(num + 1, num + 4);
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= num[i] - mi; ++j) s0[i] = s0[i] * s0[i] % mod;
        }
        while (!equal()) push();
        cout << s0[1] << '\n';
    }

    return 0;
}