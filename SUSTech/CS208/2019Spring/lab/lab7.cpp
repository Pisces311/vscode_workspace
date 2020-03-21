#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e5 + 5;

int N, d;
int p1[maxn];

void cal_1D() {
    int p, dis = INT_MAX;
    up(i, 1, N) cin >> p1[i];
    sort(p1 + 1, p1 + N + 1);
    up(i, 1, N - 1) {
        int dif = p1[i + 1] - p1[i];
        if (dis > dif) {
            dis = dif;
            p = i;
        }
    }
    cout << min(p1[p], p1[p + 1]) << endl << max(p1[p], p1[p + 1]) << endl;
}

struct d2 {
    int in;
    int x, y;
    bool operator<(const d2& a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
    double operator-(const d2& a) const {
        return sqrt(1.0 * pow((x - a.x), 2) + pow((y - a.y), 2));
    }
    void show() { cout << x << ' ' << y << endl; }
} p2[maxn], tmp2[maxn];

struct ppair {
    int f, s;
    double dis;
};

bool cy2(const d2& a, const d2& b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

ppair div2(int l, int r) {
    ppair d = {l, r, INT_MAX};
    if (l == r) return d;
    if (l + 1 == r) return (ppair){l, r, p2[l] - p2[r]};
    int mid = (l + r) / 2;
    ppair x = div2(l, mid);
    ppair y = div2(mid + 1, r);
    d = x.dis <= y.dis ? x : y;
    int top = 0;
    up(i, l, r) if (fabs(p2[mid].x - p2[i].x) <= d.dis) tmp2[++top] = p2[i];
    sort(tmp2 + 1, tmp2 + top + 1, cy2);
    up(i, 1, top) for (int j = i + 1;
                       j <= i + 7 && tmp2[j].y - tmp2[i].y < d.dis && j <= top;
                       ++j) if (d.dis > tmp2[i] - tmp2[j])
        d = {min(tmp2[i].in, tmp2[j].in), max(tmp2[i].in, tmp2[j].in),
             tmp2[i] - tmp2[j]};
    return d;
}

void cal_2D() {
    up(i, 1, N) cin >> p2[i].x >> p2[i].y;
    sort(p2 + 1, p2 + N + 1);
    up(i, 1, N) p2[i].in = i;
    ppair ans = div2(1, N);
    p2[ans.f].show();
    p2[ans.s].show();
}

struct d3 {
    int in;
    int x, y, z;
    bool operator<(const d3& a) const {
        return x < a.x || (x == a.x && y < a.y) ||
               (x == a.x && y == a.y && z < a.z);
    }
    double operator-(const d3& a) const {
        return sqrt(1.0 * pow((x - a.x), 2) + pow((y - a.y), 2) +
                    pow((z - a.z), 2));
    }
    void show() { cout << x << ' ' << y << ' ' << z << endl; }
} p3[maxn], tmp3[maxn];

bool cy3(const d3& a, const d3& b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

ppair div3(int l, int r) {
    ppair d = {l, r, INT_MAX};
    if (l == r) return d;
    if (l + 1 == r) return (ppair){l, r, p3[l] - p3[r]};
    int mid = (l + r) / 2;
    ppair x = div3(l, mid);
    ppair y = div3(mid + 1, r);
    d = x.dis <= y.dis ? x : y;
    int top = 0;
    up(i, l, r) if (fabs(p3[mid].x - p3[i].x) <= d.dis) tmp3[++top] = p3[i];
    sort(tmp3 + 1, tmp3 + top + 1, cy3);
    up(i, 1, top) {
        for (int j = i + 1; j <= i + 27 && j <= top; ++j)
            if (d.dis > tmp3[i] - tmp3[j])
                d = {min(tmp3[i].in, tmp3[j].in), max(tmp3[i].in, tmp3[j].in),
                     tmp3[i] - tmp3[j]};
    }
    return d;
}

void cal_3D() {
    up(i, 1, N) cin >> p3[i].x >> p3[i].y >> p3[i].z;
    sort(p3 + 1, p3 + N + 1);
    up(i, 1, N) p3[i].in = i;
    ppair ans = div3(1, N);
    p3[ans.f].show();
    p3[ans.s].show();
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> N >> d;
    if (d == 1)
        cal_1D();
    else if (d == 2)
        cal_2D();
    else
        cal_3D();

    return 0;
}