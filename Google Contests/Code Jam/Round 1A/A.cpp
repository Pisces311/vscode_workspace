#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0, j = 1; i < s.size(); i++) {
        while (j < s.size() && s[i] == s[j]) j++;
        if (j == s.size())
            ans += s[i];
        else if (s[i] > s[j])
            ans += s[i];
        else {
            ans += s[i];
            ans += s[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int Case = 1; Case <= T; Case++) {
        cout << "Case #" << Case << ": ";
        solve();
    }

    return 0;
}