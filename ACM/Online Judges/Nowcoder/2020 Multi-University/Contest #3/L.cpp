#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

string s, t;

bool solve() {
    for (int i = 0; i < 6; ++i) {
        if (tolower(s[i]) != t[i]) return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    t = "lovely";
    cin >> s;
    if (solve())
        cout << "lovely\n";
    else
        cout << "ugly\n";

    return 0;
}