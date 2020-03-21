#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, x) for (int i = head[x]; i != -1; i = edge[i].next)

const int maxn = 1e4 + 5;
const int maxm = 2e4 + 5;
const int maxq = 5e4 + 5;

int N, M, Q;
int power[maxn], parent[maxn], ans[maxq], top;
map<pair<int, int>, bool> m;
pair<int, int> tunnel[maxm], q[maxq];

inline void init() {
    mem(parent, -1);
    m.clear();
    top = 0;
}

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
    if (power[x] > power[y] || (power[x] == power[y] && x < y)) {
        parent[x] = tmp;
        parent[y] = x;
    } else {
        parent[x] = y;
        parent[y] = tmp;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int case_num = 0;
    while (~scanf("%d", &N)) {
        ++case_num;
        if (case_num != 1) printf("\n");
        init();
        up(i, 0, N - 1) scanf("%d", &power[i]);
        scanf("%d", &M);
        up(i, 1, M) {
            int f, s;
            scanf("%d %d", &f, &s);
            if (f < s) swap(f, s);
            m[make_pair(f, s)] = true;
        }
        scanf("%d", &Q);
        up(i, 1, Q) {
            char des[10];
            scanf("%s", des);
            if (des[0] == 'q') {
                scanf("%d", &q[i].first);
                q[i].second = -1;
            } else {
                scanf("%d %d", &q[i].first, &q[i].second);
                if (q[i].first < q[i].second) swap(q[i].first, q[i].second);
                m[make_pair(q[i].first, q[i].second)] = false;
            }
        }
        for (map<pair<int, int>, bool>::iterator i = m.begin(); i != m.end();
             ++i) {
            if (!i->second) continue;
            Union(i->first.first, i->first.second);
        }
        dn(i, Q, 1) {
            if (q[i].second == -1) {
                int root = find(q[i].first);
                if (power[root] == power[q[i].first])
                    ans[++top] = -1;
                else
                    ans[++top] = root;
            } else
                Union(q[i].first, q[i].second);
        }
        dn(i, top, 1) printf("%d\n", ans[i]);
    }

    return 0;
}