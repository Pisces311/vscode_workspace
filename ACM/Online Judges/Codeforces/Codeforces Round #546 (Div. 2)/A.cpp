#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
//#define DEBUG
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e2 + 5;

int n, k;
pii chap[maxn];

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> chap[i].first >> chap[i].second;
    cin >> k;
    up(i, 1, n) {
        if (k > chap[i].second)
            continue;
        else {
            cout << n - i + 1 << endl;
            break;
        }
    }

    return 0;
}