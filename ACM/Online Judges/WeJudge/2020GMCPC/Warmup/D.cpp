#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 200 + 5;

char s[maxn];
int num[30];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> (s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len; ++i) ++num[s[i] - 'a' + 1];
    int Max = *max_element(num + 1, num + 30);
    for (int i = 1; i <= len; ++i) {
        cout << s[i];
        if (num[s[i] - 'a' + 1] == Max) cout << "（出现了" << Max << "次）";
    }
    cout << '\n';

    return 0;
}