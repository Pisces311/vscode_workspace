#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 5e4 + 5;

int n, x, y;
int a[maxn];

int check(int score) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] > score) ++cnt;
    return cnt;
}

int solve() {
    for (int i = 0; i <= 101; ++i) {
        int pass = check(i);
        if (x <= pass && pass <= y && x <= n - pass && n - pass <= y) return i;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << solve() << '\n';

    return 0;
}