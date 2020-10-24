#include <bits/stdc++.h>
using namespace std;
#define For(i, j, k) for (int i = (int)(j); i <= (int)(k); i++)
#define CLR(a, b) memset(a, b, sizeof(a))
#define ll long long
#define fi first
#define se second
// const int N=25+10;
/*pair<int,int> s[N];
int dp[i][j];
int main(){
    int n, k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&s[i].se,&s[i].fi);
    }
    sort(s+1,s+1+n);
    CLR(s,-1);
    dp[1][1]=s[1].fi*s[1].se;
    ll hei=s[1].fi;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(dp[i-1][j]>=0){

            }
        }
    }
}*/
ll pow2[40];
ll get(ll x, ll y, int k) {
    if (k == 0) return 1;
    ll t = pow2[k - 1];
    if (x <= t && y <= t) {
        return t * t + 1 - get(y, -x + t + 1, k - 1);
    } else if (x > t && y <= t) {
        return t * t + get(x - t, y, k - 1);
    } else if (x > t && y > t) {
        return t * t * 2 + get(x - t, y - t, k - 1);
    } else {
        return t * t * 4 + 1 - get(-y + 2 * t + 1, x, k - 1);
    }
}
const int N = 1e6 + 10;

struct Node {
    int x, y;
    long long v;
} s[N];
bool cmp(Node x, Node y) { return x.v < y.v; }
int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    pow2[0] = 1;
    For(i, 1, 35) pow2[i] = pow2[i - 1] * 2;
    int n, k;
    scanf("%d%d", &n, &k);
    For(i, 1, n) {
        scanf("%d%d", &s[i].x, &s[i].y);
        s[i].v = get(s[i].x, s[i].y, k);
    }
    sort(s + 1, s + 1 + n, cmp);
    For(i, 1, n) { printf("%d %d\n", s[i].x, s[i].y); }
}