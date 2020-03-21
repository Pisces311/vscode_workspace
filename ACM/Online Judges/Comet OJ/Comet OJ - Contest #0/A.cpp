#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const ll mod = 1e9 + 7;
const int maxn = 1e7;

int T, n;
ll ans;
double sq;
int divi[maxn], top;

void solve(int nn) {
    top = 0;
    up(i, 1, sqrt(nn)) {
        if (nn % i == 0) divi[++top] = i;
    }
    up(i, 1, top){
        ans += ((divi[i] * (nn / divi[i])) % mod * (divi[i] + nn / divi[i])) % mod;
        ans %= mod;
    }
    printf("%d %lld\n", top, ans);
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(T);
    while (T--) {
        ans = 0;
        scan(n);
        sq = sqrt(n);
        if (sq == (int)sq)
            printf("infty\n");
        else if (n % 4 != 0)
            printf("0 0\n");
        else {
            solve(n / 4);
        }
    }

    return 0;
}