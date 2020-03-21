#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e6 + 5;

ll n, cnt = 0;
ll a[maxn];

void solve(ll l, ll r) {
    if (l > r)
        return;
    else if (a[l] == a[r])
        solve(l + 1, r - 1);
    else {
        if (a[l] < a[r]) {
            ++cnt;
            a[l + 1] += a[l];
            solve(l + 1, r);
        } else {
            ++cnt;
            a[r - 1] += a[r];
            solve(l, r - 1);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:\\source\\Visual Studio Code\\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    solve(1, n);
    cout << cnt << endl;
    
    return 0;
}