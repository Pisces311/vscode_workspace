#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int tot = 0;
    for (char ch : s) tot += ch - '0';
    for (int i = 0; i <= 9; i++) {
        if ((tot + i) % 9 == 0) {
            string ans = "";
            if (i == 0) {
                ans += s[0];
                ans += '0';
                for (int i = 1; i < s.size(); i++) ans += s[i];
                cout << ans << '\n';
            } else {
                for (int j = 0; j < s.size(); j++) {
                    if (s[j] <= i + '0')
                        ans += s[j];
                    else {
                        ans += i + '0';
                        ans += s[j];
                        for (int k = j + 1; k < s.size(); k++) ans += s[k];
                        cout << ans << '\n';
                        return;
                    }
                }
                ans += i + '0';
                cout << ans << '\n';
            }
            return;
        }
    }
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