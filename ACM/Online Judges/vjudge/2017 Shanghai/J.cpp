#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int T, N;
int a[maxn], dif[maxn];
int pos[1000005], neg[1000005];

bool solve() {
    int pf = 1, nf = 1, pr = 1, nr = 1;
    for (int i = 0; i <= N; ++i)
        if (dif[i] > 0)
            pos[pr++] = i;
        else if (dif[i] < 0)
            neg[nr++] = i;
    while (pf < pr && nf < nr) {
        int pos_id = pos[pf], neg_id = neg[nf];
        if (dif[pos_id] > -dif[neg_id]) {
            if (pos_id - neg_id >= 3) {
                dif[pos_id] += dif[neg_id];
                ++nf;
            } else
                return false;
        } else if (dif[pos_id] < -dif[neg_id]) {
            if (pos_id - neg_id >= 3) {
                dif[neg_id] += dif[pos_id];
                ++pf;
            } else
                return false;
        } else {
            if (pos_id - neg_id >= 3) {
                ++pf;
                ++nf;
            } else
                return false;
        }
    }
    if (pf != pr || nf != nr) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    int cas = 0;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> a[i];
        a[N + 1] = 0;
        for (int i = 0; i <= N; ++i) dif[i] = a[i] - a[i + 1];
        cout << "Case #" << ++cas << ": ";
        if (solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}