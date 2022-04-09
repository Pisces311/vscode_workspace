#include <bits/stdc++.h>
using namespace std;

void solve() {
    using pii = pair<int, int>;

    int N;
    cin >> N;
    vector<int> value(N + 1), pointTo(N + 1), inDeg(N + 1);
    for (int i = 1; i <= N; i++) cin >> value[i];
    for (int i = 1; i <= N; i++) {
        cin >> pointTo[i];
        inDeg[pointTo[i]]++;
    }
    long long ans = 0;
    queue<pii> q;
    for (int i = 1; i <= N; i++)
        if (!inDeg[i]) q.push(make_pair(i, value[i]));
    vector<int> minPre(N + 1, INT_MAX);
    while (!q.empty()) {
        auto [u, val] = q.front();
        q.pop();
        int v = pointTo[u];
        if (!v)
            ans += val;
        else {
            inDeg[v]--;
            if (minPre[v] == INT_MAX)
                minPre[v] = val;
            else {
                ans += max(val, minPre[v]);
                minPre[v] = min(minPre[v], val);
            }
            if (!inDeg[v]) q.push(make_pair(v, max(minPre[v], value[v])));
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