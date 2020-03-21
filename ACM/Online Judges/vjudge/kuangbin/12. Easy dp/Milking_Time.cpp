//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

//#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxm = 1e3 + 5;

struct interval {
    int s, e, eff;
    friend bool operator<(const interval& a, const interval& b) {
        return a.s < b.s;
    }
} a[maxm];

int N, M, R;
int dp[maxm];

int main() {
#ifdef DEBUG
    freopen("D:/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> N >> M >> R;
    up(i, 1, M) {
        cin >> a[i].s >> a[i].e >> a[i].eff;
        a[i].e += R;
    }
    sort(a + 1, a + M + 1);
    up(i, 1, M) dp[i] = a[i].eff;
    up(i, 1, M) {
        up(j, 1, i - 1) if (a[j].e <= a[i].s) {
            dp[i] = max(dp[i], dp[j] + a[i].eff);
        }
    }
    cout << *max_element(dp + 1, dp + M + 1) << endl;

    return 0;
}