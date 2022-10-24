#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    map<char, int> ma = {{'S', 0}, {'M', 1}, {'L', 2}};
    while (T--) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        if (ma[s[n - 1]] != ma[t[m - 1]]) {
            if (ma[s[n - 1]] < ma[t[m - 1]])
                cout << "<\n";
            else
                cout << ">\n";
        } else if (n != m) {
            if (n < m && s[n - 1] == 'L' || n > m && s[n - 1] == 'S')
                cout << "<\n";
            else
                cout << ">\n";
        } else
            cout << "=\n";
    }

    return 0;
}