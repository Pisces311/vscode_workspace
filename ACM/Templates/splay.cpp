#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int inf = 0x3f3f3f3f;

int root, tot;

struct Node {
    int fa, cnt, val, son_num;
    int ch[2];
} t[maxn];

inline void push_up(int u) {
    t[u].son_num = t[t[u].ch[0]].son_num + t[t[u].ch[1]].son_num + t[u].cnt;
}

void rotate(int x) {
    int y = t[x].fa, z = t[y].fa, k = (t[y].ch[1] == x);
    t[z].ch[t[z].ch[1] == y] = x;
    t[x].fa = z;
    t[y].ch[k] = t[x].ch[k ^ 1];
    t[t[x].ch[k ^ 1]].fa = y;
    t[x].ch[k ^ 1] = y;
    t[y].fa = x;
    push_up(y);
    push_up(x);
}

void splay(int x, int goal) {
    while (t[x].fa != goal) {
        int y = t[x].fa;
        int z = t[y].fa;
        if (z != goal)
            (t[y].ch[0] == x) ^ (t[z].ch[0] == y) ? rotate(x) : rotate(y);
        rotate(x);
    }
    if (goal == 0) root = x;
}

void add(int x) {
    int u = root, fa = 0;
    while (u && t[u].val != x) {
        fa = u;
        u = t[u].ch[x > t[u].val];
    }
    if (u)
        ++t[u].cnt;
    else {
        u = ++tot;
        if (fa) t[fa].ch[x > t[fa].val] = u;
        t[tot] = {fa, 1, x, 1, {0, 0}};  // Notice!
    }
    splay(u, 0);
}

// 将查询节点旋转至根
inline void find(int x) {
    int u = root;
    if (!u) return;
    while (t[u].ch[x > t[u].val] && x != t[u].val) u = t[u].ch[x > t[u].val];
    splay(u, 0);
}

// 0: 查找x的前驱
// 1: 查找x的后继
// 返回所求节点编号
int pre_next(int x, int f) {
    find(x);
    if ((t[root].val > x && f) || (t[root].val < x && !f)) return root;
    int u = t[root].ch[f];
    while (t[u].ch[f ^ 1]) u = t[u].ch[f ^ 1];
    return u;
}

void del(int x) {
    int pre = pre_next(x, 0);
    int next = pre_next(x, 1);
    splay(pre, 0);
    splay(next, pre);
    int del = t[next].ch[0];
    if (t[del].cnt > 1) {
        --t[del].cnt;
        splay(del, 0);
    } else
        t[next].ch[0] = 0;
}

//查找排名为x的数
int kth(int x) {
    int u = root;
    if (t[u].son_num < x) return -1;
    while (true) {
        int y = t[u].ch[0];
        if (x > t[y].son_num + t[u].cnt) {
            x -= t[y].son_num + t[u].cnt;
            u = t[u].ch[1];
        } else if (t[y].son_num >= x)
            u = y;
        else
            return t[u].val;
    }
}

inline void init() {
    root = tot = 0;
    memset(t, 0, sizeof(t));
    add(inf);
    add(-inf);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Notice!
    init();
    int T;
    cin >> T;
    while (T--) {
        int op, x;
        cin >> op >> x;
        if (op == 1)
            add(x);
        else if (op == 2)
            del(x);
        else if (op == 3) {
            find(x);
            cout << t[t[root].ch[0]].son_num << '\n';
        } else if (op == 4)
            cout << kth(x + 1) << '\n';
        else if (op == 5)
            cout << t[pre_next(x, 0)].val << '\n';
        else if (op == 6)
            cout << t[pre_next(x, 1)].val << '\n';
    }

    return 0;
}