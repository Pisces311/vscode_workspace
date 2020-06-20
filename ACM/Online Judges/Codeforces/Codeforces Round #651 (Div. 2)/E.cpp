#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int n;
char s[maxn], t[maxn];
vector<int> v;

int cnt(char* str) {
    int cnt0 = 0;
    for (int i = 1; i <= n; ++i)
        if (str[i] == '0') ++cnt0;
    return cnt0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> (s + 1) >> (t + 1);
    if (cnt(s) != cnt(t)) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '0' && t[i] == '1')
            v.push_back(0);
        else if (s[i] == '1' && t[i] == '0')
            v.push_back(1);
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i : v) {
        if (i == 0) {
            if (cnt1) {
                --cnt1;
                ++cnt0;
            } else
                ++cnt0;
        } else {
            if (cnt0) {
                --cnt0;
                ++cnt1;
            } else
                ++cnt1;
        }
    }
    cout << cnt0 + cnt1 << '\n';

    return 0;
}