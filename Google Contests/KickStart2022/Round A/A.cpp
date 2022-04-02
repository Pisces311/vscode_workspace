#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    int idx = 0;
    for (char ch : s) {
        while (idx < t.size() && ch != t[idx]) {
            idx++;
            cnt++;
        }
        if (idx == t.size()) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        idx++;
    }
    cout << cnt + t.size() - idx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cout << "Case #" << cas << ": ";
        solve();
    }

    return 0;
}