#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

int t, n;
int num[maxn];

vector<int> fac;

void get(int n) {
    fac.clear();
    memset(num, 0, sizeof(num));
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fac.push_back(i);
            int cnt = fac.size() - 1;
            while (n % i == 0) {
                n /= i;
                ++num[cnt];
            }
        }
    }
    if (n > 1) {
        fac.push_back(n);
        int cnt = fac.size() - 1;
        ++num[cnt];
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        get(n);
        if (fac.size() >= 3) {
            cout << "YES\n";
            int a = 1, b = 1;
            for (int i = 1; i <= num[0]; ++i) a *= fac[0];
            for (int i = 1; i <= num[1]; ++i) b *= fac[1];
            int c = n / a / b;
            cout << a << ' ' << b << ' ' << c << '\n';
        } else {
            if (fac.size() == 1) {
                if (num[0] >= 6) {
                    cout << "YES\n";
                    int a = fac[0], b = fac[0] * fac[0], c = n / a / b;
                    cout << a << ' ' << b << ' ' << c << '\n';
                } else
                    cout << "NO\n";
            } else if (fac.size() == 2) {
                if (num[0] + num[1] <= 3) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    int a = fac[0], b = fac[1], c = n / a / b;
                    cout << a << ' ' << b << ' ' << c << '\n';
                }
            }
        }
    }

    return 0;
}