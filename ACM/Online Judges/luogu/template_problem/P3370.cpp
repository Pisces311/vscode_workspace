#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1.5e3 + 5;

int N;
char s[maxn];
map<unsigned int, int> ma;

unsigned int BKDRHash(const char str[], int l, int r) {
    unsigned int seed = 131;  // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    for (int i = l; i <= r; ++i) hash = hash * seed + str[i];
    return (hash & 0x7FFFFFFF);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        ++ma[BKDRHash(s, 1, len)];
    }
    printf("%u\n", ma.size());

    return 0;
}