#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int len1, len2;
char s1[20], s2[20];
int v[256], h1[20], h2[20], hh1[6], hh2[6];

void attack(const char s[20], const int &len, int h[20], int hh[6]) {
    up(i, 0, len - 1) h[v[s[i]]]++;
    up(i, 3, 17) hh[h[i]]++;
}

int MaxCard(int h[20], int hh[6], int len, int x, int y) {
    if (x == 4 && hh[4] == 0) return -1;
    if (x == 3 && hh[3] + hh[4] == 0) return -1;
    if (x == 2 && hh[2] + hh[3] + hh[4] == 0) return -1;
    if (len == 0) return -1;
    int ma = 0;
    dn(i, 17, 3) if (h[i] >= x) {
        ma = i;
        break;
    }
    if (x == 4) return ma;
    if (x == 3 && y == 0) return ma;
    if (x == 3 && y == 2 && (hh[2] + hh[3] + hh[4] >= 2)) return ma;
    if (x == 3 && y == 1 && len >= 4) return ma;
    if (x == 2) return ma;
    if (x == 1) return ma;
    return -1;
}

bool gank() {
    if (len1 == 0) return 1;
    mem(h1, 0);
    mem(hh1, 0);
    attack(s1, len1, h1, hh1);
    if (h1[17] == 1 && h1[16] == 1 && len1 == 2) return 1;
    if (hh1[4] == 1 && len1 == 6) return 1;
    if (hh1[4] == 1 && len1 == 4)
        return 1;
    else if (hh1[4] == 0 && hh1[3] == 1 &&
             ((len1 == 3) || (len1 == 4 && hh1[1] == 1) ||
              (len1 == 5 && hh1[2] == 1)))
        return 1;
    else if (hh1[4] == 0 && hh1[3] == 0 && hh1[2] == 1 && hh1[1] == 0 &&
             len1 == 2)
        return 1;
    else if (len1 == 1)
        return 1;
    mem(h2, 0);
    mem(hh2, 0);
    attack(s2, len2, h2, hh2);
    if (h2[17] >= 1 && h2[16] >= 1) return 0;
    if (h1[17] >= 1 && h1[16] >= 1) return 1;
    if (MaxCard(h1, hh1, len1, 4, 0) < MaxCard(h2, hh2, len2, 4, 0))
        return 0;
    else if (MaxCard(h1, hh1, len1, 4, 0) > MaxCard(h2, hh2, len2, 4, 0))
        return 1;
    if (MaxCard(h1, hh1, len1, 3, 2) != -1 &&
        MaxCard(h1, hh1, len1, 3, 2) >= MaxCard(h2, hh2, len2, 3, 2))
        return 1;
    if (MaxCard(h1, hh1, len1, 3, 1) != -1 &&
        MaxCard(h1, hh1, len1, 3, 1) >= MaxCard(h2, hh2, len2, 3, 1))
        return 1;
    if (MaxCard(h1, hh1, len1, 3, 0) != -1 &&
        MaxCard(h1, hh1, len1, 3, 0) >= MaxCard(h2, hh2, len2, 3, 0))
        return 1;
    if (MaxCard(h1, hh1, len1, 2, 0) != -1 &&
        MaxCard(h1, hh1, len1, 2, 0) >= MaxCard(h2, hh2, len2, 2, 0))
        return 1;
    if (MaxCard(h1, hh1, len1, 1, 0) != -1 &&
        MaxCard(h1, hh1, len1, 1, 0) >= MaxCard(h2, hh2, len2, 1, 0))
        return 1;
    return 0;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int T, i, j, k;
    v['Y'] = 17;
    v['X'] = 16;
    v['2'] = 15;
    v['A'] = 14;
    v['K'] = 13;
    v['Q'] = 12;
    v['J'] = 11;
    v['T'] = 10;
    for (i = 3; i <= 9; i++) v['0' + i] = i;
    scanf("%d\n", &T);
    while (T--) {
        gets(s1);
        gets(s2);
        len1 = strlen(s1);
        len2 = strlen(s2);
        if (gank())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}