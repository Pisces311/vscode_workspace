#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int n, k;
int parent[maxn];
int a[maxn], top = 0;
ll ded = 0;

inline int find(int x) {
    int pos;
    for (pos = x; parent[pos] > 0; pos = parent[pos])
        ;
    while (pos != x) {
        int tmp = parent[x];
        parent[x] = pos;
        x = tmp;
    }
    return pos;
}

inline void Union(int u, int v) {
    int tmp = parent[u] + parent[v];
    if (parent[u] > parent[v]) {
        parent[u] = v;
        parent[v] = tmp;
    } else {
        parent[v] = u;
        parent[u] = tmp;
    }
}

ll power(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x;
            res = res % mod;
        }
        x = x * x;
        x = x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);
    memset(parent, -1, sizeof(parent));
    up(i, 1, n - 1) {
        int u, v, col;
        scanf("%d %d %d", &u, &v, &col);
        if (col == 0) Union(find(u), find(v));
    }
    up(i, 1, n) if (parent[i] < 0) a[++top] = -parent[i];
    up(i, 1, top) {
        ded += power(a[i], k);
        ded %= mod;
    }
    ll ans = power(n, k);
    ans %= mod;
    cout << (ans - ded + mod) % mod << endl;

    return 0;
}