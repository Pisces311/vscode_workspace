#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 4e5 + 5;
const int inf = 0x3f3f3f3f;

int q, x, mex = 0;
int qry[maxn], cnt[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q >> x;
    for (int i = 1; i <= q; ++i) {
        cin >> qry[i];
        qry[i] %= x;
    }
    int round = 1, mex = 0;
    for (int i = 1; i <= q; ++i) {
        int query = qry[i];
        ++cnt[query];
        while (true) {
            while (cnt[mex] >= round) ++mex;
            if (mex >= x) {
                ++round;
                mex -= x;
            } else
                break;
        }

        cout << (round - 1) * x + mex << '\n';
    }

    return 0;
}