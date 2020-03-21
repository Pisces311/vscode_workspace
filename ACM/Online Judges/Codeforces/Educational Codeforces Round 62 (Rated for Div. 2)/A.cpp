#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e4 + 5;

int n, day = 0;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    int ma = 0, late = 0;
    up(i, 1, n) if (i > late) {
        ma = max(ma, a[i]);
        while (ma > late) {
            ++late;
            ma = max(ma, a[late]);
        }
        ++day;
    }
    cout << day << endl;

    return 0;
}