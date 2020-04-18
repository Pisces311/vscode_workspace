#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int T, k;
int an[maxn], bn[maxn], cn[maxn];
int l1, l2, l3;
char s[maxn];
int ans[maxn];
int ans_l;
int len;
int greed[maxn];
int gred_l;
int bul[20];

int cmp() {
    for (int i = 0; i < k; i++) {
        if (ans[i] != greed[i]) return ans[i] < greed[i];
    }
    return 0;
}

typedef struct tup {
    int a, b, c;
    void init(int _a, int _b, int _c) {
        a = _a;
        b = _b;
        c = _c;
    }
} TUP;

int cmptup(TUP x, TUP y) {
    if (x.a == y.a && x.b == y.b && x.c == y.c) return 1;
    if (x.a != y.a) return x.a > y.a;
    if (x.b != y.b) return x.b > y.b;
    return x.c > y.c;
}

int select(int p1, int p2, int p3, int cnt) {
    while (p1 < (l1 - 2) || p2 < (l2 - 2) || p3 < (l3 - 2)) {
        if (cnt < 3) break;
        int pos = 0;
        TUP val;
        val.init(0, 0, 0);
        if (p1 < (l1 - 2)) {
            TUP tmp;
            tmp.init(an[p1], an[p1 + 1], an[p1 + 2]);
            if (cmptup(tmp, val)) {
                val.init(an[p1], an[p1 + 1], an[p1 + 2]);
                pos = 1;
            }
        }
        if (p2 < (l2 - 2)) {
            TUP tmp;
            tmp.init(bn[p2], bn[p2 + 1], bn[p2 + 2]);
            if (cmptup(tmp, val)) {
                val.init(bn[p2], bn[p2 + 1], bn[p2 + 2]);
                pos = 2;
            }
        }
        if (p3 < (l3 - 2)) {
            TUP tmp;
            tmp.init(cn[p3], cn[p3 + 1], cn[p3 + 2]);
            if (cmptup(tmp, val)) {
                val.init(cn[p3], cn[p3 + 1], cn[p3 + 2]);
                pos = 3;
            }
        }
        if (pos == 1)
            p1 += 3;
        else if (pos == 2)
            p2 += 3;
        else
            p3 += 3;
        greed[gred_l++] = val.a;
        greed[gred_l++] = val.b;
        greed[gred_l++] = val.c;
        cnt -= 3;
    }
    int tmp0 = k;
    sort(greed, greed + tmp0, [](int a, int b) { return a > b; });
    if (cnt == 0 && cmp()) {
        for (int i = 0; i < k; i++) ans[i] = greed[i];
        return 1;
    }
    return 0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> s >> k;
        int flag = 0;
        int len = strlen(s);
        l1 = l2 = l3 = 0;
        for (int i = 0; i < len; i++) {
            int t = s[i] - '0';
            if (t % 3 == 0) {
                an[l1++] = t;
            } else if (t % 3 == 1) {
                bn[l2++] = t;
            } else {
                cn[l3++] = t;
            }
            if (t == 0) flag = 1;
        }
        sort(an, an + l1, [](int a, int b) { return a > b; });
        sort(bn, bn + l2, [](int a, int b) { return a > b; });
        sort(cn, cn + l3, [](int a, int b) { return a > b; });
        ans_l = 0;
        for (int i = 0; i < k; i++) ans[ans_l++] = 0;
        int p1, p2, p3;
        int cnt = 0;
        if (k >= 2 && l2 >= 1 && l3 >= 1 && l1 >= ((k - 2) % 3)) {
            p1 = p2 = p3 = gred_l = 0;
            greed[gred_l++] = bn[p2++];
            greed[gred_l++] = cn[p3++];
            for (int i = 0; i < (k - 2) % 3; i++) greed[gred_l++] = an[i];
            p1 += (k - 2) % 3;
            cnt = k - 2 - (k - 2) % 3;
            select(p1, p2, p3, cnt);
        }
        if (k >= 4 && l2 >= 2 && l3 >= 2 && l1 >= ((k - 4) % 3)) {
            p1 = p2 = p3 = gred_l = 0;
            greed[gred_l++] = bn[p2++], greed[gred_l++] = bn[p2++];
            greed[gred_l++] = cn[p3++], greed[gred_l++] = cn[p3++];
            for (int i = 0; i < (k - 4) % 3; i++) greed[gred_l++] = an[i];
            p1 += (k - 4) % 3;
            cnt = k - 4 - (k - 4) % 3;
            select(p1, p2, p3, cnt);
        }
        if (l1 >= (k % 3)) {
            p1 = p2 = p3 = gred_l = 0;
            for (int i = 0; i < k % 3; i++) greed[gred_l++] = an[i];
            p1 += k % 3;
            cnt = k - k % 3;
            select(p1, p2, p3, cnt);
        }
        if (ans[0]) {
            for (int i = 0; i < k; i++) cout << ans[i];
        } else {
            if (flag && k == 1)
                cout << 0;
            else
                cout << -1;
        }
        cout << '\n';
    }

    return 0;
}
