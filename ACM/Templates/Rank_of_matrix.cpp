#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e1 + 5;

int n, m;
int a[maxn][maxn];

int gcd(int a, int b) { return a % b == 0 ? b : gcd(b, a % b); }

void change_line(int q, int w, int e) {
    for (int i = 1; i <= m; ++i) swap(a[q][i], a[w][i]);
}

int Rank(int n, int m) {
    int s = 0;
    for (int i = 1, j = 1; i <= n && j <= m; i++, j++) {
        int chk = 0;
        for (int v = i; v <= n; ++v) {
            if (a[v][j] != 0) {
                chk = v;
                break;
            }
        }
        if (chk == 0)
            i--;
        else {
            change_line(chk, i, j);
            for (int w = i + 1; w <= n; ++w) {
                if (a[w][j] != 0) {
                    int g = gcd(a[w][j], a[i][j]);
                    int pa = a[i][j] / g, pb = a[w][j] / g;
                    for (int z = j; z <= m; ++z)
                        a[w][z] = a[w][z] * pa - a[i][z] * pb;
                }
            }
            s++;
        }
    }
    return s;
}