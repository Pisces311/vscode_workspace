#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e5 + 5;
const int maxm = 1e5 + 5;

int n, m;
int a[maxn], b[maxm];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    int cnt_ao = 0, cnt_ae = 0;
    int cnt_bo = 0, cnt_be = 0;
    cin >> n >> m;
    up(i, 1, n) cin >> a[i];
    up(i, 1, m) cin >> b[i];
    up(i, 1, n) {
        if (a[i] & 1)
            ++cnt_ao;
        else
            ++cnt_ae;
    }
    up(i, 1, m) {
        if (b[i] & 1)
            ++cnt_bo;
        else
            ++cnt_be;
    }
    cout << min(cnt_ao, cnt_be) + min(cnt_ae, cnt_bo) << endl;

    return 0;
}