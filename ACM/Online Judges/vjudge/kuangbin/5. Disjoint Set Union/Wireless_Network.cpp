#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e3 + 5;

struct coor {
    int x, y, id;
} cpt[maxn];

int N, x, y;
double d;
int parent[maxn];
vector<coor> rep;
char opr;

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
    int x = find(u), y = find(v);
    if (x == y) return;
    int tmp = parent[x] + parent[y];
    if (x < y) {
        parent[x] = tmp;
        parent[y] = x;
    } else {
        parent[x] = y;
        parent[y] = tmp;
    }
}

double dis(coor c1, coor c2) {
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> N >> d;
    up(i, 1, N) {
        cin >> cpt[i].x >> cpt[i].y;
        cpt[i].id = i;
    }
    mem(parent, -1);
    while (cin >> opr) {
        if (opr == 'O') {
            cin >> x;
            rep.push_back(cpt[x]);
            up(i, 0, (int)rep.size() - 2) if (dis(cpt[x], rep[i]) <= d)
                Union(x, rep[i].id);
        } else {
            cin >> x >> y;
            if (find(x) == find(y))
                cout << "SUCCESS" << endl;
            else
                cout << "FAIL" << endl;
        }
    }

    return 0;
}