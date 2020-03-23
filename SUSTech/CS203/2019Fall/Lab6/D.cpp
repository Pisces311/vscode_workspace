#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int n;
int nxt[maxn];
char p[maxn];

void get_next(char *p) {
    nxt[0] = 0;
    int plen = strlen(p);
    for (int q = 1, k = 0; q < plen; ++q) {
        while (k > 0 && p[q] != p[k]) k = nxt[k - 1];
        if (p[q] == p[k]) ++k;
        nxt[q] = k;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> p;
        int plen = strlen(p);
        get_next(p);
        if (!nxt[plen - 1])
            cout << plen << '\n';
        else if (plen % (plen - nxt[plen - 1])) {
            cout << plen - nxt[plen - 1] - plen % (plen - nxt[plen - 1])
                 << '\n';
        } else
            cout << "0\n";
    }

    return 0;
}