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

const int maxn = 2e5 + 5;

int n;
int a[maxn];
int tmp = 0, ans = 0;

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif

    cin >> n;
    up(i, 1, n) cin >> a[i];
    up(j, 0, 1) up(i, 1, n) {
        if (a[i] == 1) {
            ++tmp;
            ans = max(ans, tmp);
        } else
            tmp = 0;
    }
    ans = max(ans, tmp);
    cout << ans << endl;

    return 0;
}