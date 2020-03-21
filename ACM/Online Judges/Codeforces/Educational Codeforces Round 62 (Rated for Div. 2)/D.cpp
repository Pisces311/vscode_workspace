#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 5e2 + 5;

int n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    a[3] = 6;
    up(i, 4, n) { a[i] = a[i - 1] + i * (i - 1); }
    cout << a[n] << endl;

    return 0;
}