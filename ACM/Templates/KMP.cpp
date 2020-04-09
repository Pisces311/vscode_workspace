#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int nxt[maxn];

void get_next(char *p) {
    nxt[0] = 0;
    int plen = strlen(p);
    for (int q = 1, k = 0; q < plen; ++q) {
        while (k > 0 && p[q] != p[k]) k = nxt[k - 1];
        if (p[q] == p[k]) ++k;
        nxt[q] = k;
    }
}

int KMP(char *s, char *p) {
    get_next(p);
    int slen = strlen(s), plen = strlen(p);
    int cnt = 0;
    for (int i = 0, j = 0; i < slen; ++i) {
        while (j > 0 && p[j] != s[i]) j = nxt[j - 1];
        if (p[j] == s[i]) ++j;
        if (j == plen) {
            ++cnt;
            j = nxt[j - 1];
        }
    }
    return cnt;
}