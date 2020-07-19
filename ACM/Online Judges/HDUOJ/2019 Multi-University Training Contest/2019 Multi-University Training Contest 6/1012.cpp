#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    int id, val;
    bool operator<(const node& a) const { return val < a.val; }
};

int T, n;
int heap[maxn], fa[maxn], son[maxn];
priority_queue<node> pq;
bool turn;
ll a, b;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> heap[i];
            son[i] = 0;
        }
        fa[1] = 1;
        for (int i = 2; i <= n; ++i) {
            fa[i] = i / 2;
            ++son[i / 2];
        }
        for (int i = 1; i <= n; ++i)
            if (!son[i]) pq.push({i, heap[i]});
        a = b = 0;
        turn = true;
        while (!pq.empty()) {
            node t = pq.top();
            pq.pop();
            if (turn) {
                a += t.val;
                --son[fa[t.id]];
                if (!son[fa[t.id]]) pq.push({fa[t.id], heap[fa[t.id]]});
            } else {
                b += t.val;
                --son[fa[t.id]];
                if (!son[fa[t.id]]) pq.push({fa[t.id], heap[fa[t.id]]});
            }
            turn = !turn;
        }
        cout << a << ' ' << b << '\n';
    }

    return 0;
}