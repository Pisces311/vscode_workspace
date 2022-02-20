#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, m, p;
        cin >> n >> m >> p;
        vector<string> orders(n);
        for (string& i : orders) cin >> i;
        vector<string> forbidden(m);
        for (string& i : forbidden) cin >> i;
        set<int> s;
        for (string i : forbidden) {
            bitset<10> bit(i);
            s.insert(bit.to_ulong());
        }
        int ans = n * p;
        for (int i = 0; i < (1 << p); i++) {
            if (s.count(i)) continue;
            int complaints = 0;
            for (string& str : orders) {
                for (int j = 0; j < p; j++) {
                    if ((i & (1 << j) && str[p - 1 - j] == '1') ||
                        (!(i & (1 << j)) && str[p - 1 - j] == '0'))
                        continue;
                    complaints++;
                }
            }
            ans = min(ans, complaints);
        }
        cout << "Case #" << tc << ": ";
        cout << ans << '\n';
    }
    return 0;
}