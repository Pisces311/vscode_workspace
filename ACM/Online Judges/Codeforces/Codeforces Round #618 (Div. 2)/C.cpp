#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    int val;
    bitset<31> bit;
    bool operator<(const node& rhs) const {
        return bit.to_ulong() > rhs.bit.to_ulong();
    }
} a[maxn];

int n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].val;
        a[i].bit = a[i].val;
    }
    for (int i = 30; i >= 0; --i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[j].bit[i]) ++cnt;
        }
        if (cnt > 1) {
            for (int j = 1; j <= n; ++j) {
                a[j].bit[i] = 0;
            }
        }
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) cout << a[i].val << " \n"[i == n];

    return 0;
}