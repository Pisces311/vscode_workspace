#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    if (n >= 3)
        cout << "BigBoLang\n";
    else if (n >= 2)
        cout << "YingHuaTang\n";
    else if (n >= 1)
        cout << "XiZhiTang\n";
    else
        cout << "None\n";

    return 0;
}