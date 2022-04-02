#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<vector<int>> printers(3, vector<int>(4));
    for (vector<int>& i : printers) {
        for (int& j : i) {
            cin >> j;
        }
    }
    vector<int> ink(printers[0]);
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            ink[j] = min(ink[j], printers[i][j]);
        }
    }
    int more = accumulate(ink.begin(), ink.end(), 0) - 1000000;
    if (more < 0)
        cout << "IMPOSSIBLE\n";
    else {
        for (int i = 0; i < 4; i++) {
            if (more > ink[i]) {
                more -= ink[i];
                ink[i] = 0;
            } else {
                ink[i] -= more;
                more = 0;
            }
        }
        for (int i : ink) cout << i << ' ';
        cout << '\n';
    }
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