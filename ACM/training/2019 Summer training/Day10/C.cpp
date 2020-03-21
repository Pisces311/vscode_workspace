#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

ll n;
ll pre[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

ll work(ll k) { return pow(n, 1.0 / k) - 1; }

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (cin >> n) {
        ll ans1 = 0, ans2 = 0, ans3 = 0;
        for (int i = 0; i < 17; i++) ans1 += work(pre[i]);
        for (int i = 0; i < 17; i++)
            for (int j = i + 1; j < 17; j++) ans2 += work(pre[i] * pre[j]);
        for (int i = 0; i < 17; i++)
            for (int j = i + 1; j < 17; j++)
                for (int k = j + 1; k < 17; k++)
                    ans3 += work(pre[i] * pre[j] * pre[k]);
        cout << ans1 + ans3 - ans2 + 1 << endl;
    }

    return 0;
}