#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    double n, x, y;
    scanf("%lf%lf%lf", &n, &x, &y);
    double n1 = n;
    double n2 = n / (1.0 - (1.0 - x / 100) * (y / 100));
    double n3 = n2 * (1.0 - x / 100);
    double n4 = n3 * (1.0 - y / 100);
    double n5 = n4;
    printf("%.4lf %.4lf %.4lf %.4lf %.4lf", n1, n2, n3, n4, n5);

    return 0;
}