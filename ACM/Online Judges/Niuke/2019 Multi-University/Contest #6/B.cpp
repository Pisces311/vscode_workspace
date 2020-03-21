#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
char bit[130];
int ans[10];
vector<int> v;

inline int cal_num(int i) {
    int num = 0;
    for (int j = 0; j <= 15; ++j) num += (bit[i + j] - '0') * pow(2, 15 - j);
    return num;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    int cas = 0;
    while (T--) {
        printf("Case #%d: ", ++cas);
        scanf("%s", bit + 1);
        for (int i = 1, j = 1; i <= 128; i += 16, ++j) ans[j] = cal_num(i);
        int pre[10]{0};
        for (int i = 1; i <= 8; ++i) {
            if (ans[i] == 0)
                pre[i] = pre[i - 1] + 1;
            else
                continue;
        }
        int ma = *max_element(pre + 1, pre + 9);
        if (ma <= 1) {
            for (int i = 1; i <= 8; ++i)
                printf("%x%c", ans[i], i == 8 ? '\n' : ':');
            continue;
        }
        v.clear();
        bool last = false;
        for (int i = 1; i <= 8; ++i)
            if (pre[i] == ma) {
                v.push_back(i);
                if (i == 8) last = true;
            }
        int pos = -1;
        if (last && v.size() > 1) {
            if (v.size() != 2 || (v.size() == 2 && v[v.size() - 2] - ma != 0))
                pos = v[v.size() - 2];
            else
                pos = v[v.size() - 1];
        } else
            pos = v[v.size() - 1];
        if (pos - ma == 0) printf(":");
        for (int i = 1; i <= 8; ++i) {
            if (i == pos - ma + 1) {
                printf(":");
                i = pos;
            } else {
                printf("%x", ans[i]);
                if (i != 8) printf(":");
            }
        }
        printf("\n");
    }

    return 0;
}