#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
//#define DEBUG
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

int n, k;

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> k;
    int route = n - 1 + min(k - 1, n - k);
    int pick = n;
    int thrw = n + 1;
    cout << route + pick + thrw << endl;

    return 0;
}