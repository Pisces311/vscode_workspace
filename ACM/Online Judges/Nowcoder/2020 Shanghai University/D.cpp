#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int n;
vector<char> v;

void print() {
    for (char i : v) cout << i;
    cout << '\n';
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    if (n == 1) {
        cout << "1\n";
        cout << "1\n";
    } else if (n == 2) {
        cout << "2\n";
        cout << "1\n";
        cout << "00\n";
    } else {
        cout << n - 1 << '\n';
        v.push_back('1');
        v.push_back('1');
        print();
        for (int i = 3; i <= n; ++i) {
            v.pop_back();
            v.push_back('0');
            v.push_back('1');
            print();
        }
    }

    return 0;
}