#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
char s[maxn];

int seg(int &off, int len) {
    if (s[off] == '1') {
        ++off;
        for (int i = 1; i < len; ++i) {
            if (s[off++] != '0') return 999;
        }
        return s[off++] - '0';
    }
    for (int i = 1; i < len; ++i)
        if (s[off++] != '9') return 999;
    return s[off++] - '0' - 10;
}

int cut(int len) {
    int Max = -999, Min = 999, off = 0, cnt = 0;
    while (off < n) {
        int t = seg(off, len);
        if (t == 999) return 999;
        Max = max(Max, t);
        Min = min(Min, t);
        ++cnt;
    }
    if (cnt < 2) return 999;
    if (off != n) return 999;
    return Max - Min;
}

int sub(char *a, char *b, int len) {
    int ans = 0;
    for (int i = 0; i < len && ans > -10 && ans < 10; ++i) {
        ans *= 10;
        ans += a[i] - b[i];
    }
    return ans;
}

int solve(int len) {
    char *Min = s;
    int dif = 0;
    for (int i = len; i < n; i += len) {
        if (len != 1 && s[i] == '0') return 10;
        int ret = sub(s + i, Min, len);
        if (ret < 0) {
            Min = s + i;
            dif -= ret;
        } else
            dif = max(dif, ret);
    }
    return dif;
}

int find() {
    for (int i = 0; i < n - 1; ++i)
        if (s[i] == '1' && s[i + 1] == '0') return i;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        int ans = 9;
        cin >> n >> s;
        for (int i = 1; i * 2 <= n; ++i)
            if (n % i == 0) ans = min(ans, solve(i));
        int one = find(), zero = one;
        while (s[zero + 1] == '0') ++zero;
        ans = min({ans, cut(zero - one), cut(zero - one + 1)});
        cout << ans << '\n';
    }

    return 0;
}