#include <assert.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef double db;
int n;
int a[4001000], l[400100], id[400100];
ll gx[30][30];
ll jc[30];
const ll M = 998244353ll;
bool cmp(const int aa, const int bb) { return l[aa] < l[bb]; }
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "a", stdout);
    scanf("%d", &n);
    int le = 0;
    int mxlen = 0;
    for (int i = 1; i <= n; i++) {
        char s[20];
        // scanf("%s", s);
        // assert(strlen(s) == le || le == 0);
        // le = strlen(s);
        // sscanf(s, "%d", &a[i]);
        scanf("%d", &a[i]);
        int t = a[i], q = 0;
        while (t) {
            q++;
            t /= 10;
        }
        l[i] = q;
        id[i] = i;
        mxlen = max(mxlen, l[i]);
    }
    sort(id + 1, id + 1 + n, cmp);
    jc[0] = 1;
    for (int i = 1; i < 22; i++) {
        jc[i] = jc[i - 1] * 10 % M;
    }
    memset(gx, 0, sizeof(gx));
    ll wa = 0;
    for (int now = 1; now <= n; now++) {
        int i = id[now];
        int len = 0, t = a[i];
        while (t) {
            int la = t % 10;
            for (int j = 0; j < 22; j++) {
                wa = (wa + gx[len][j] * la % M * jc[j] % M);
                if (wa >= M) wa -= M;
            }

            wa = (wa + (jc[len * 2 + 1]) * la % M * (n - now + 1) % M) % M;
            len++;
            t /= 10;
        }
        int pos = 1;
        int nowlen = l[i] - 1;
        for (int j = 0; j < mxlen; j++) {
            gx[j][pos]++;
            if (nowlen) {
                pos += 2;
                nowlen--;
            } else
                pos++;
        }
    }
    memset(gx, 0, sizeof(gx));
    for (int now = 1; now <= n; now++) {
        int i = id[now];
        int len = 0, t = a[i];
        while (t) {
            int la = t % 10;
            for (int j = 0; j < 22; j++) {
                wa = (wa + gx[len][j] * la % M * jc[j] % M);
                if (wa >= M) wa -= M;
            }

            wa = (wa + (jc[len * 2]) * la % M * (n - now + 1) % M) % M;
            len++;
            t /= 10;
        }
        int pos = 0;
        int nowlen = l[i];
        for (int j = 0; j < mxlen; j++) {
            gx[j][pos]++;
            if (nowlen) {
                pos += 2;
                nowlen--;
            } else
                pos++;
        }
    }
    printf("%lld", wa);
}