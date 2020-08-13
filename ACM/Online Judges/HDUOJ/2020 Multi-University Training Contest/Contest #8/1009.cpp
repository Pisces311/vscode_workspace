#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e6 + 5;

int T, n;
int num[26];
char s[maxn], sec[maxn], mi[maxn];
vector<int> divi;

inline void init() {
    memset(num, 0, sizeof(num));
    divi.clear();
}

bool ok(int x) {
    if (n % x != 0) return false;
    for (int i = 0; i < 26; ++i)
        if (num[i] % x != 0) return false;
    return true;
}

int find(int len) {
    int k = 0, i = 0, j = 1;
    while (k < len && i < len && j < len) {
        if (sec[(i + k) % len] == sec[(j + k) % len]) {
            k++;
        } else {
            sec[(i + k) % len] > sec[(j + k) % len] ? i = i + k + 1
                                                    : j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    i = min(i, j);
    return i;
}

bool check(int len) {
    for (int i = len + 1; i <= n; i += len) {
        int st = i, ed = i + len - 1;
        copy(s + st, s + ed + 1, sec);
        int p = find(len) + st;
        for (int j = 1; j <= len; ++j) {
            if (mi[j] != s[p]) return false;
            ++p;
            if (p > ed) p -= len;
        }
    }
    return true;
}

bool solve() {
    for (int k : divi) {
        int len = n / k;
        copy(s + 1, s + len + 1, sec);
        int p = find(len);
        for (int i = 1; i <= len; ++i) {
            mi[i] = sec[p];
            p = (p + 1) % len;
        }
        if (check(len)) return true;
    }
    return false;
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
        cin >> n >> (s + 1);
        init();
        for (int i = 1; i <= n; ++i) ++num[s[i] - 'a'];
        for (int i = 2; i <= n; ++i) {
            if (ok(i)) divi.push_back(i);
        }
        if (solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}