#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int T;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    for (int kas = 1; kas <= T; ++kas) {
        int h, m;
        char s[5], c1[10], c2[10];
        scanf("%d:%d %s", &h, &m, s);
        scanf("%s %s", c1, c2);
        if (s[0] == 'A') {
            if (h == 12) h = 0;
        } else {
            if (h != 12) h += 12;
        }
        if (c1[0] == 'B') {
            if (c2[0] == 'W') h -= 13;
            if (c2[0] == 'L') h -= 8;
            if (c2[0] == 'M') h -= 5;
        } else if (c1[0] == 'W') {
            if (c2[0] == 'B') h += 13;
            if (c2[0] == 'L') h += 5;
            if (c2[0] == 'M') h += 8;
        } else if (c1[0] == 'L') {
            if (c2[0] == 'B') h += 8;
            if (c2[0] == 'W') h -= 5;
            if (c2[0] == 'M') h += 3;
        } else {
            if (c2[0] == 'B') h += 5;
            if (c2[0] == 'W') h -= 8;
            if (c2[0] == 'L') h -= 3;
        }
        int tag = 0;
        if (h >= 24) {
            h -= 24;
            tag = 1;
        } else if (h < 0) {
            h += 24;
            tag = -1;
        }
        if (h == 0) {
            s[0] = 'A';
            h = 12;
        } else if (h < 12) {
            s[0] = 'A';
        } else if (h == 12) {
            s[0] = 'P';
        } else {
            s[0] = 'P';
            h -= 12;
        }
        printf("Case %d: ", kas);
        if (tag == 0) printf("Today ");
        if (tag == 1) printf("Tomorrow ");
        if (tag == -1) printf("Yesterday ");
        printf("%d:%02d %s\n", h, m, s);
    }

    return 0;
}