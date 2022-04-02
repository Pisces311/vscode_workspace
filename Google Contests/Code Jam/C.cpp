#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    int ans = 0, cur = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] >= cur + 1) {
            cur++;
        }
        ans = max(ans, cur);
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