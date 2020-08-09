#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int, int>
#define pll pair<ll, ll>
#define IT iterator
#define PB push_back
#define MK make_pair
#define fi first
#define se second
#define For(i, j, k) for (int i = (int)(j); i <= (int)(k); i++)
#define Rep(i, j, k) for (int i = (int)(j); i >= (int)(k); i--)
#define CLR(a, v) memset(a, v, sizeof(a));
#define CPY(a, b) memcpy(a, b, sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
#define all(v) v.begin(), v.end()
using namespace std;
const int maxn = 1e5 + 10;
int v1[maxn], v2[maxn];
char s1[maxn], s2[maxn];
int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s%s", s1 + 1, s2 + 1);
        CLR(v1, 0);
        CLR(v2, 0);
        For(i, 1, n) {
            if (s1[i] != s2[i]) v1[i] = 1;
            if (s2[i] != '0') v2[i]++;
            v1[i] += v1[i - 1];
            v2[i] += v2[i - 1];
        }
        s1[n + 1] = s2[n + 1] = '0';
        v1[n + 1] = v1[n + 2] = v1[n];
        v2[n + 1] = v2[n + 2] = v2[n];
        int ans = v1[n];
        int cnt = 0;
        For(i, 1, n + 1) {
            int res = v1[n + 2] - v1[i] + v2[i - 1] + ('1' - s2[i]) + cnt + 1;
            // printf("res=%d\n",res);
            if (s1[i] == '1')
                res++;
            else
                cnt++;
            ans = min(ans, res);
        }
        printf("%d\n", ans);
    }
}
