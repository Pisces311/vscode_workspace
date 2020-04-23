#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e3 + 5;
constexpr int inf = 0x3f3f3f3f;

int n, k;
int diff[maxn], x[maxn], suf[maxn];
int need[maxn][15];
char s[maxn][8];
char digit[][8] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                   "1101011", "1101111", "1010010", "1111111", "1111011"};

int get_cnt(int i, int j) {
    int cnt = 0;
    for (int k = 0; k < 8; ++k) {
        if (s[i][k] == '0' && digit[j][k] == '1')
            ++cnt;
        else if (s[i][k] == '1' && digit[j][k] == '0')
            return inf;
    }
    return cnt;
}

void get_diff(int i) {
    int Min = 10;
    for (int j = 0; j <= 9; ++j) {
        need[i][j] = get_cnt(i, j);
        Min = min(Min, need[i][j]);
    }
    diff[i] = Min;
}

int get(int i, int avl) {
    for (int j = 9; j >= 0; --j) {
        if (avl >= need[i][j]) {
            x[i] = j;
            return avl - need[i][j];
        }
    }
    return -1;
}

int enlarge(int i, int avl) {
    int Max = 0, id = -1;
    for (int j = 9; j >= 0; --j) {
        if (need[i][j] == inf) continue;
        int num = need[i][j] - need[i][x[i]];
        if (num <= avl && Max < num) {
            Max = num;
            id = j;
        }
    }
    if (id == -1) return 0;
    int ret = need[i][id] - need[i][x[i]];
    x[i] = id;
    return ret;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) get_diff(i);
    for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] + diff[i];
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        int avl = k - suf[i + 1];
        if (avl < 0) {
            flag = false;
            break;
        }
        k -= avl;
        int ret = get(i, avl);
        if (ret == -1) {
            flag = false;
            break;
        }
        k += ret;
    }
    if (!flag) {
        cout << "-1\n";
        return 0;
    }
    for (int i = n; i >= 1; --i) k -= enlarge(i, k);
    if (k)
        cout << "-1\n";
    else {
        for (int i = 1; i <= n; ++i) cout << x[i];
        cout << '\n';
    }

    return 0;
}