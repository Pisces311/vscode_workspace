#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxm = 1e5 + 5;
const int inf = 0x3f3f3f3f;

ll n, m, k, cnt = 0;
ll spe[maxm];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> spe[i];
        spe[i] -= 1;
    }
    ll op = 0;
    spe[m + 1] = LLONG_MAX;
    for (int i = 1; i <= m; ++i) {
        ll page = (spe[i] - cnt) / k;
        int tmp = 1;
        while ((spe[i + 1] - cnt) / k == page) {
            ++i;
            ++tmp;
        }
        ++op;
        cnt += tmp;
    }
    cout << op << endl;

    return 0;
}