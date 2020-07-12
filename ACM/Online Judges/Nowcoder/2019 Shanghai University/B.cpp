#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
int ord[30];
char s1[maxn], s2[maxn];

char cmp() {
    int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
    for (int i = 1; i <= min(len1, len2); ++i) {
        int num1 = s1[i] - 'a' + 1, num2 = s2[i] - 'a' + 1;
        if (num1 != num2) {
            if (ord[num1] < ord[num2])
                return '<';
            else
                return '>';
        }
    }
    if (len1 < len2)
        return '<';
    else if (len1 == len2)
        return '=';
    else
        return '>';
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= 26; ++i) {
        char tmp;
        cin >> tmp;
        ord[tmp - 'a' + 1] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> (s1 + 1) >> (s2 + 1);
        cout << cmp() << '\n';
    }

    return 0;
}