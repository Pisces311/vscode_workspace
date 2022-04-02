#include <bits/stdc++.h>
using namespace std;

void solve() {
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!i && !j)
                cout << "..";
            else
                cout << "+-";
        }
        cout << "+\n";
        for (int j = 0; j < C; j++) {
            if (!i && !j)
                cout << "..";
            else
                cout << "|.";
        }
        cout << "|\n";
    }
    for (int j = 0; j < C; j++) {
        cout << "+-";
    }
    cout << "+\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int Case = 1; Case <= T; Case++) {
        cout << "Case #" << Case << ": \n";
        solve();
    }

    return 0;
}