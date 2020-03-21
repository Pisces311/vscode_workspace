#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 3e4 + 5;

int n, m, k;
int parent[maxn], stu[maxn];

inline int find(int x) {
    int pos;
    for (pos = x; parent[pos] >= 0; pos = parent[pos])
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

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        mem(parent, -1);
        up(i, 1, m) {
            cin >> k;
            up(j, 1, k) cin >> stu[j];
            up(j, 2, k) {
                int x = find(stu[1]), y = find(stu[j]);
                if (x != y) Union(x, y);
            }
        }
        if (parent[0] < 0)
            cout << -parent[0] << endl;
        else
            cout << -parent[parent[0]] << endl;
    }

    return 0;
}