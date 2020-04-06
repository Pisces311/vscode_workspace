#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 35;

int T, n;
ll k;
ll a[maxn];
int num[100], tmp[100];

void transfer(ll x) {
    memset(tmp, 0, sizeof(tmp));
    int top = 0;
    while (x) {
        tmp[++top] = x % k;
        x /= k;
    }
    for (int i = 1; i <= top; ++i) num[i] += tmp[i];
}

bool check() {
    for (int i = 1; i <= 99; ++i)
        if (num[i] > 1) return false;
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
    while (T--) {
        memset(num, 0, sizeof(num));
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            transfer(a[i]);
        }
        if (check())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}