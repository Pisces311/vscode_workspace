#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

ll ans = 0;
int n;
string s;

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> s;
    up(i, 0, n - 1) {
        if ((s[i] - '0') & 1) continue;
        ans += i + 1;
    }
    cout << ans << endl;
    return 0;
}