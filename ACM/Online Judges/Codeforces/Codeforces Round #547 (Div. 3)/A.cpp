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

double n, m;

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif

    cin >> n >> m;
    double ans = m / n;
    if ((int)ans != ans) {
        cout << -1 << endl;
        return 0;
    }
    int cnt_2 = 0, cnt_3 = 0;
    while ((int)ans % 2 == 0) {
        ans /= 2;
        ++cnt_2;
    }
    while ((int)ans % 3 == 0) {
        ans /= 3;
        ++cnt_3;
    }
    if (ans != 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << cnt_2 + cnt_3 << endl;

    return 0;
}