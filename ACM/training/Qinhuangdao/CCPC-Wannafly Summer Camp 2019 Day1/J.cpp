#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n;
int deg[maxn], u[maxn], type[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "dis", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &type[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &u[i]);
    for (int i = 1; i <= n; i++)
        if (u[i]) deg[u[i]]++;
    int ret = 0, reti = -1;
    for (int i = 1; i <= n; i++)
        if (type[i] == 1) {
            int dis = 1, j = i;
            while (u[j] && deg[u[j]] == 1) {
                j = u[j];
                ++dis;
            }
            if (dis > ret) {
                ret = dis;
                reti = i;
            }
        }
    printf("%d\n", ret);
    vector<int> output;
    for (int i = 0; i < ret; i++) {
        output.push_back(reti);
        reti = u[reti];
    }
    for (int i = 0; i < ret; i++) {
        if (i) printf(" ");
        printf("%d", output[ret - 1 - i]);
    }
    puts("");

    return 0;
}