#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        int N, M;
        cin >> N >> M;
        vector<int> bags(N);
        for (int& i : bags) cin >> i;
        int tot = accumulate(bags.begin(), bags.end(), 0);
        cout << "Case #" << cas << ": ";
        cout << tot % M << '\n';
    }

    return 0;
}