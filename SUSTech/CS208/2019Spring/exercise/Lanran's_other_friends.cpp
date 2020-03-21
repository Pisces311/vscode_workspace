#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e5 + 5;

struct interval {
    int l, r;
} itv[maxn];

int T, N, cnt;

bool operator<(const interval& a, const interval& b) { return a.r < b.r; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cnt = 1;
        cin >> N;
        for(int i = 1; i <= N; ++i) cin >> itv[i].l >> itv[i].r;
        sort(itv + 1, itv + N + 1);
        int late = itv[1].r;
        for(int i = 2; i <= N; ++i) {
            if (itv[i].l > late) {
                late = itv[i].r;
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}