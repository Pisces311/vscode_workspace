#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int N = 2e5 + 5;

struct node {
    node *l, *r;
    int h, num, v;
    ll key;
    bool lazy;
};

char opr;
int t, n, del_num;
ll m, base, x;

struct avl {
    node* root;
    int ex;
    void del(node* k) {
        if (k == NULL) return;
        if (k->l != NULL) del(k->l);
        if (k->r != NULL) del(k->r);
        delete (k);
    }
    static node* creat(ll val, node* l, node* r) {
        node* t = new node();
        t->key = val;
        t->l = l;
        t->h = 0;
        t->num = 1;
        t->v = 1;
        t->lazy = 0;
        return t;
    }
    static int h(node* t) { return (t ? t->h : 0); }
    static int g(node* t) { return (t ? t->num : 0); }
    static int me(node* t) { return ((t && t->lazy == 0) ? t->v : 0); }
    static node* llr(node* k2) {
        node* k1;
        k1 = k2->l;
        k2->l = k1->r;
        k1->r = k2;
        k2->h = max(h(k2->l), h(k2->r)) + 1;
        k1->h = max(h(k1->l), k2->h) + 1;
        k2->num = g(k2->l) + g(k2->r) + me(k2);
        k1->num = g(k1->l) + g(k2) + me(k1);
        return k1;
    }
    static node* r_rrr(node* k1) {
        node* k2;
        k2 = k1->r;
        k1->r = k2->l;
        k2->l = k1;
        k1->h = max(h(k1->l), h(k1->r)) + 1;
        k2->h = max(h(k2->r), k1->h) + 1;
        k1->num = g(k1->l) + g(k1->r) + me(k1);
        k2->num = g(k2->r) + g(k1) + me(k2);
        return k2;
    }
    static node* r_lrr(node* k1) {
        k1->l = r_rrr(k1->l);
        return llr(k1);
    }
    static node* r_rlr(node* k1) {
        k1->r = llr(k1->r);
        return r_rrr(k1);
    }
    node* nsert(node* k, ll key) {
        if (k == NULL)
            k = creat(key, NULL, NULL);
        else if (key < k->key) {
            k->l = nsert(k->l, key);
            if (h(k->l) - h(k->r) == 2) {
                if (key < k->l->key)
                    k = llr(k);
                else
                    k = r_lrr(k);
            }
        } else if (key > k->key) {
            k->r = nsert(k->r, key);
            if (h(k->r) - h(k->l) == 2) {
                if (key < k->r->key)
                    k = r_rlr(k);
                else
                    k = r_rrr(k);
            }
        } else {
            if (k->lazy) {
                k->v = 1;
                k->lazy = 0;
            } else
                k->v++;
        }
        k->h = max(h(k->l), h(k->r)) + 1;
        k->num = g(k->l) + g(k->r) + me(k);
        return k;
    }
    void dfs(node* k, ll x) {
        if (k == NULL) return;
        if (k->key < x) {
            if (!k->lazy) {
                del_num += k->v;
                k->lazy = 1;
            }
            dfs(k->l, x);
            dfs(k->r, x);
        } else
            dfs(k->l, x);
        k->num = g(k->r) + g(k->l) + me(k);
    }
    void init() {
        del(root);
        root = NULL;
    }
    void ist(ll key) { root = nsert(root, key); }
    void lazy_rmv(ll x) { dfs(root, x); }
    node* search(int x) {
        if (x > size()) return NULL;
        int sum = x;
        node* k = root;
        while (k != NULL) {
            if (sum > g(k->l) && sum <= g(k->l) + (k->lazy ? 0 : k->v)) break;
            if (sum <= g(k->l))
                k = k->l;
            else {
                sum -= g(k->l) + (k->lazy ? 0 : k->v);
                k = k->r;
            }
        }
        return k;
    }
    int size() {
        if (root != NULL) return root->num;
        return 0;
    }
} avl_tree;

inline void init() {
    base = del_num = 0;
    avl_tree.init();
}

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    scan(t);
    while (t--) {
        init();
        scanf("%d%lld", &n, &m);
        up(i, 0, n - 1) {
            scanf(" %c %lld", &opr, &x);
            switch (opr) {
                case 'I':
                    if (x >= m) avl_tree.ist(x - base);
                    break;
                case 'A':
                    base += x;
                    break;
                case 'S':
                    base -= x;
                    avl_tree.lazy_rmv(m - base);
                    break;
                case 'Q':
                    node* p = avl_tree.search(avl_tree.size() - x + 1);
                    if (p != NULL)
                        printf("%lld\n", p->key + base);
                    else
                        print(-1);
                    break;
            }
        }
        print(del_num);
    }
    return 0;
}