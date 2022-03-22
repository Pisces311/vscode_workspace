#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (!x && !y) {
            cout << "0\n";
            continue;
        }
        int a = sqrt(x * x + y * y);
        if (a * a == x * x + y * y)
            cout << "1\n";
        else
            cout << "2\n";
    }
    return 0;
}