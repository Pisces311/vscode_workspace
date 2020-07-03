#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e6 + 5;
const int inf = 0x3f3f3f3f;

//欧拉函数还可以用于求模奇素数时原根的个数。
//如p是一个奇素数，则p的原根个数为f(p-1).

//单个欧拉函数
int eular(int n) {
    int ret = 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            n /= i, ret *= i - 1;
            while (n % i == 0) n /= i, ret *= i;
        }
    if (n > 1) ret *= n - 1;
    return ret;
}

//筛法求欧拉函数
ll phi[maxn];

int main() {
    int a, b;
    for (int i = 1; i <= maxn; i++) phi[i] = i;
    for (int i = 2; i <= maxn; i += 2) phi[i] /= 2;
    for (int i = 3; i <= maxn; i += 2)
        if (phi[i] == i) {
            for (int j = i; j <= maxn; j += i) phi[j] = phi[j] / i * (i - 1);
        }
    while (~scanf("%d%d", &a, &b)) {
        ll ans = 0;
        for (int i = a; i <= b; i++) ans += phi[i];
        cout << ans << endl;
    }
    return 0;
}