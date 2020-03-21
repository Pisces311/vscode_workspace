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

const int maxn = 3e5 + 5;

int n;
int col[maxn];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(n);
    up(i, 1, n) scan(col[i]);
    int dis1, dis2;
    up(i, 1, n) if (col[i] != col[n]){
        dis1 = n - i;
        break;
    }
    dn(i, n, 1) if (col[i] != col[1]){
        dis2 = i - 1;
        break;
    }
    print(max(dis1, dis2));

    return 0;
}