#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

#ifdef DEBUG
const int maxn = 10 + 5;
#endif
#ifndef DEBUG
const int maxn = 1e5 + 5;
#endif
map<string, int> ma;

int n, m, k, num = 0, num_a, num_b;
int parent[maxn], ans[maxn], top = 0;
string a, b;

inline void get_num(string s, int& num_x){
    auto ite = ma.find(s);
    if (ite == ma.end()) {
        ma[s] = ++num;
        num_x = num;
    } else
        num_x = ite->second;
}

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

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    memset(parent, -1, sizeof(parent));
    up(i, 1, m) {
        cin >> a >> b;
        get_num(a, num_a);
        get_num(b, num_b);
        int x = find(num_a), y = find(num_b);
        if (x != y) Union(find(num_a), find(num_b));
    }
    up(i, 1, n) if (parent[i] < 0) ans[++top] = -parent[i];
    sort(ans + 1, ans + top + 1);
    int sum = 0;
    dn(i, top, 1) if (k) { 
        sum += ans[i];
        --k;
    }
    cout << sum << endl;

    return 0;
}