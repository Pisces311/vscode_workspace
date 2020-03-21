#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e6 + 5;

ll n, k;
bool mod[maxn];

bool solve() {
    for (int i = 1; i <= min((ll)2e6, k); ++i) {
        if (mod[n % i])
            return false;
        else
            mod[n % i] = true;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    if (solve())
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}